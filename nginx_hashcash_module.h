#ifndef PROOF_H
#define PROOF_H 1
#include <stddef.h>
#include <stdint.h>
#include <time.h>

#define NGX_MODULE_HASHCASH_INVALID_HEADER -1
#define NGX_MODULE_HASHCASH_EXPIRED -2
#define NGX_MODULE_HASHCASH_WORK_NEEDED -3
#define NGX_MODULE_HASHCASH_DUPLICATE -4

typedef int16_t (*nginx_hashcash_module_validate_token_is_new_t)(const char *nonce, int ttl);

typedef struct {
    char * header_token;
    size_t header_length;
    time_t check_time;
    uint16_t max_time_diff;
    uint16_t min_work_needed;
    nginx_hashcash_module_validate_token_is_new_t validate_token_function;
} nginx_hashcash_module_check_ctx_t;

int16_t nginx_hashcash_module_count_leading_zeros(const unsigned char* data, size_t len);
int16_t nginx_hashcash_module_get_pow_amount(const char* header_token, size_t len);

int16_t nginx_hashcash_module_validate_token(nginx_hashcash_module_check_ctx_t *ctx);

#endif