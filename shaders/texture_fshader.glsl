// Object Fshader
#version 330 core

struct DirLight_t {
    vec3 color;
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
};

struct Material_t {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct PointLight_t {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float Kc;
    float Kl;
    float Kq;
};

struct SpotLight_t {
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
    float inner_cutoff;
    float outer_cutoff;
};

vec3 getPointLight(PointLight_t pl, float dist)
{
    float attenuation = 1.0f / (pl.Kc + pl.Kl * dist + pl.Kq * dist * dist);
    return pl.ambient * attenuation + pl.diffuse * attenuation + pl.specular * attenuation;
}

vec3 getAmbientLight(vec3 color, vec3 light_color, float intensity)
{
    return color * light_color * intensity;
}

vec3 getDiffuseLight(vec3 color, vec3 light_color, float intensity, vec3 unit_normal, vec3 path)
{
    return color * light_color * intensity * max(dot(unit_normal, path), 0.0f);
}

vec3 getSpecularLight(vec3 color, vec3 light_color, vec3 path, vec3 dir, vec3 norm, float shininess)
{
    return color * light_color * pow(max(dot(path, normalize(reflect(-dir, norm))), 0.0f), shininess);
}

vec3 getDirLight(DirLight_t dl, Material_t ma, vec3 unit_normal, vec3 spec_light_path, vec3 world_pos, vec3 color)
{
    return getAmbientLight(ma.ambient * color, dl.color, dl.ambientIntensity) +
       getDiffuseLight(ma.diffuse * color, dl.color, dl.diffuseIntensity, unit_normal, normalize(dl.direction - world_pos)) +
       getSpecularLight(ma.specular * color, dl.color, spec_light_path, dl.direction, unit_normal, ma.shininess);
}

vec3 getSpotLight(SpotLight_t sl, PointLight_t pl, Material_t ma, vec3 norm, vec3 spec_light_path, vec3 world_pos, vec3 color)
{
    vec3 path = normalize(pl.position - world_pos);
    float theta = dot(path, normalize(sl.direction));
    vec3 pointlight = getPointLight(pl, length(pl.position - world_pos));
    if (theta > sl.inner_cutoff) {
        return pointlight + getAmbientLight(ma.ambient * color, pl.ambient, sl.ambientIntensity) +
               getDiffuseLight(ma.diffuse * color, pl.diffuse, sl.diffuseIntensity, norm, path) +
               getSpecularLight(ma.specular * color, pl.specular, spec_light_path, sl.direction, norm, ma.shininess);
    }
    return pointlight;

}

uniform sampler2D uTexture; // model colors
uniform vec3 uCamPos;
uniform DirLight_t uDirLight;
uniform Material_t uMaterial;
uniform PointLight_t uPointLight;
uniform SpotLight_t uSpotLight;

in vec3 vNormal;
in vec3 vWorldPos;
in vec2 vUVs;
out vec4 FragColor;

void main()
{
    vec3 unit_normal = normalize(vNormal);
    vec3 spec_light_path = normalize(uCamPos - vWorldPos);
    vec4 color = texture(uTexture, vUVs);

    vec3 result = getDirLight(uDirLight, uMaterial, unit_normal, spec_light_path, vWorldPos, vec3(color)) +
                  getSpotLight(uSpotLight, uPointLight, uMaterial, unit_normal, spec_light_path, vWorldPos, vec3(color));

    FragColor = vec4(result, 1.0f);
}
// end
