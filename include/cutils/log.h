/* liangc, 2015/11/24
 *
 *#include <log/log.h>
 */

#include <stdio.h>
#include <assert.h>

#define ALOGE(fmt, ...) fprintf(stderr, fmt"\n", ##__VA_ARGS__)
#define ALOGW(fmt, ...) fprintf(stderr, fmt"\n", ##__VA_ARGS__)
#define ALOGI(fmt, ...) fprintf(stderr, fmt"\n", ##__VA_ARGS__)
#define ALOGV(fmt, ...) fprintf(stderr, fmt"\n", ##__VA_ARGS__)
#define ALOGD(fmt, ...) fprintf(stderr, fmt"\n", ##__VA_ARGS__)

#define ALOGW_IF(cond, fmt, ...) \
    if (cond) { \
        ALOGW(fmt, ##__VA_ARGS__); \
    }

#define ALOG_ASSERT(condition, ...) \
    assert(condition)

#define LOG_ALWAYS_FATAL_IF(cond, ...) assert(!(cond))
#define LOG_ALWAYS_FATAL(message, ...) assert(false)
#define LOG_FATAL_IF(cond, message, ...) assert(!(cond))

#define IF_ALOGV() if(false)
