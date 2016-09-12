// threeVec.c
// ENCM 339 Fall 2015 Lab 5 Exercise D

#include "threeVec.h"

threeVec_t add_3v(threeVec_t u, threeVec_t v)
{
  threeVec_t result = { u.x + v.x, u.y + v.y, u.z + v.z };
  return result;
}

void scalar_mult(double k, const threeVec_t *src, threeVec_t *dest)
{
    dest->x = k * src->x;
    dest->y = k * src->y;
    dest->z = k * src->z;
}

double dot_product(const threeVec_t *pu, const threeVec_t *pv)
{
    return (pu->x * pv->x) + (pu->y * pv->y) + (pu->z * pv->z);
}

threeVec_t cross_product(const threeVec_t *pu, const threeVec_t *pv)
{
    threeVec_t result = {
        (pu->y * pv->z) - (pu->z * pv->y),
        (pu->z * pv->x) - (pu->x * pv->z),
        (pu->x * pv->y) - (pu->y * pv->x)
    };
    return result;
}

void array_sum(const threeVec_t *a, int n, threeVec_t *result)
{
    int i;

    result->x = 0.0;
    result->y = 0.0;
    result->z = 0.0;

    for (i = 0; i < n; i++) {
        result->x = result->x + a[i].x;
        result->y = result->y + a[i].y;
        result->z = result->z + a[i].z;
    }
}
