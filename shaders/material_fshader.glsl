// Lighting Fshader
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

// struct SpotLight_t {
//     vec3 position;
//     vec3 directions;
//     vec3 color;
//     vec3 ambientIntensity;
//     vec3 diffuseIntensity;
//     float Kc;
//     float Kl;
//     float Kq;
//     float cutoff;
// };


vec3 getSpotLight(vec3 world_pos, vec3 unit_norm, vec3 spec_light_path, Material_t uMaterial)
{
    vec3 sl_pos = vec3(10.0f, 0.0f, 10.0f);

    vec3 sl_light_dir = normalize(sl_pos - world_pos);
    float theta = dot(sl_light_dir, vec3(0.0f, -1.0f, 0.0f));
    if (theta > 0.2182f) {
        vec3 ambient = vec3(0.1f, 0.1f, 0.1f); //  * uMaterial.ambient;
        vec3 diffuse = max(dot(unit_norm, sl_light_dir), 0.0f) * vec3(0.8f, 0.8f, 0.8f); //  * uMaterial.diffuse;

        vec3 sl_reflect = reflect(-sl_light_dir, unit_norm);
        float sl_shine = pow(max(dot(spec_light_path, sl_reflect), 0.0f), uMaterial.shininess);
        vec3 specular = vec3(1.0f, 1.0f, 1.0f) * sl_shine; //  * uMaterial.specular;

        float sl_distance = length(sl_pos - world_pos);
        float attenuation = 1.0f / (1.0f + 0.09f * sl_distance + 0.032f * sl_distance * sl_distance);

        diffuse *= attenuation;
        specular *= attenuation;

        return ambient + diffuse + specular;
    } else {
        return vec3(0.0f, 0.0f, 0.0f);
    }
}

uniform vec3 uCamPos;
uniform DirLight_t uDirLight;
uniform Material_t uMaterial;

in vec3 vNormal;
in vec3 vWorldPos;

out vec4 FragColor;

void main()
{

    vec3 unit_normal = normalize(vNormal);
    vec3 dir_light_path = normalize(uDirLight.direction - vWorldPos);

    vec3 ambient_light = uDirLight.color * uDirLight.ambientIntensity * uMaterial.ambient;
    vec3 diffuse_light = uDirLight.color * uDirLight.diffuseIntensity *
        max(dot(unit_normal, dir_light_path), 0.0f) * uMaterial.diffuse;

    vec3 spec_light_path = normalize(uCamPos - vWorldPos);
    vec3 light_reflect_angle = normalize(reflect(-uDirLight.direction, unit_normal));
    float shine = pow(max(dot(spec_light_path, light_reflect_angle), 0.0f), uMaterial.shininess);
    vec3 specular_light = uDirLight.color * shine * uMaterial.specular;

    vec3 result = ambient_light + diffuse_light + specular_light;
    result += getSpotLight(vWorldPos, unit_normal, spec_light_path, uMaterial);
    FragColor = vec4(result, 1.0f);
}


// end
