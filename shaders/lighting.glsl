struct Material_t {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct DirLight_t {
    vec3 color;
    vec3 direction;
    float ambientIntensity;
    float diffuseIntensity;
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

// the halfway vector H(between viewer and light source)
// vec3 V = normalize(camPos)
// vec3 L = normalize(dirlight.direction)
// float H = dot(L, V)
// vec3 hway = acos(-V/L)//  = Ph
//
// n1 and n2 are indices of refraction.
// For air n1 be approximated to 1.0
// For glass, n2 is about 1.5
// R0 is the reflection coefficient for light incoming parallel to the normal
// Schlick's approximation of fresnel factor R(vec3 light_dir, vec3 unit_normal)
// {
//     vec3 theta = max(dot(light_dir, unit_normal), 0.0);
//     vec3 R0 = (n1 - n2)/(n1 + n2);
//     vec3 r = R0 + (1 - R0)(1 - cos(theta));
//     return r * r * r * r * r;
// }
// vec3 getFresnel(float mu2, float mu1, float ep2, float ep1)
// {
    // mu = magnetic permeability
    // ep = electric permittivity
    // mu0 is the permeability of free space, for non-magnetic materials
    // =~  μ0 = 4π×10−7 H/m ≈ 1.2566370614e−6 N/A2 or T⋅m/A or Wb/(A⋅m) or V⋅s/(A⋅m)
//     if (mu2 <= 0.0000012566370614f) {
//         vec3 theta = max(dot(unit_normal, light_path), 0.0f);
//         vec3 ra = n1 / n2 * sin(theta);
//         vec3 z2 = n2 * sqrt(1.0 - (ra * ra));
//         vec3 z1 = n1 * theta;
//         vec3 r = (z2 - z1) / (z2 + z1);
//         return r * r;
//     }
//     float z2 = sqrt(mu2/ep2);
//     float z1 = sqrt(mu1/ep1);
//     vec3 thei = max(dot(unit_normal, light_path), 0.0f) * z2;
//     vec3 thet = cross(unit_normal, light_path) * z1;
//     vec3 r = (thei - thet) / (thei + thet);
//     return r * r;
//
// }

vec3 getPointLight(PointLight_t pl, float dist)
{
    float attenuation = 1.0f / (pl.Kc + dist * pl.Kl + pl.Kq * dist * dist);
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

// vec3 blinn_phong()
// {
    // vec3 lightpath = normalize(pl.position - world_pos);
    // float lambertian = max(dot(lightpath, norm), 0.0)
    // vec3 halfdir = normalize(p
    // if (lambertian > 0.0) {
    //     vec3 halfdir = normalize(lightdir + uCamPos);
    //     float spec_angle = max(dot(halfdir, norm), 0.0);
    //     float specular = pow(spec_angle, ma.shininess);
    // return vec3 color = ambient + lambertian * diffuse + specular * vec3(1.0);
// }


vec3 getSpotLight(SpotLight_t sl, PointLight_t pl, Material_t ma, vec3 norm, vec3 spec_light_path, vec3 world_pos, vec3 color)
{
    vec3 lightpath = normalize(pl.position - world_pos);

    vec3 pointlight = getPointLight(pl, length(pl.position - world_pos));

    float theta = dot(lightpath, normalize(-sl.direction));

    // float epsilon = sl.inner_cutoff - sl.outer_cutoff;
    // float intensity = clamp((theta - sl.outer_cutoff) / epsilon, 0.0, 1.0);

    if (theta > sl.inner_cutoff) {
        return getAmbientLight(ma.ambient * color, pl.ambient, sl.ambientIntensity) +
               getDiffuseLight(ma.diffuse * color, pl.diffuse, sl.diffuseIntensity, norm, lightpath) +
               getSpecularLight(ma.specular * color, pl.specular, spec_light_path, sl.direction, norm, ma.shininess);
    }
    return vec3(0.0f, 0.0f, 0.0f);
}
