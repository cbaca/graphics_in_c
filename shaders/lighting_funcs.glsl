
// FuncAtten() = 1.0f / (Kc + Kl * d + Kq * d^2)
// d = dist(fragment, lightsource)
// Kc = constant term, Kl = linear term, Kq = quadratic term
float calcDist(vec3 src, vec3 dest)
{
    return length(src - dest);
}

float calcAttenuation(float Kc, float Kl, float Kq, float d)
{
    return 1.0f / (Kc + Kl * d + Kq * (d * d));
}
