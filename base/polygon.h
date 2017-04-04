/**
 * @file polygon.h
 */

#ifndef POLYGON_H_
#define POLYGON_H_

struct vertex_array_t {
    unsigned int length;
    unsigned int stride;
    float *array_ptr;
};

struct polygon_t {
    int num_parts;
    int model_loc;
    int num_vertices;
    unsigned int stride;
    unsigned int vao;
    unsigned int vbo;
    float *matrices[16];
    float coodrinates[3];
    int bound;
};

int polygon_init(struct polygon_t *poly, struct vertex_array_t *va);

void polygon_draw(struct polygon_t *poly);

void poly_destroy(struct polygon_t *poly);
#endif /* POLYGON_H_ */
