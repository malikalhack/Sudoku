/**
 @file      logger.h
 @version   1.0.0
 @authors   Anton Chernov
 @date      08/02/2021
*/
#ifndef LOGGER_H
#define LOGGER_H

/************************************ Error ***********************************/
/**
 @details   Function for printing error messages.
            Prints to the console the specified error message, file name,
            and the line where the error occurred.
            Enabled by default.
 */
#ifndef ERROR_PRINT
    #define ERROR_PRINT 1
#endif

#if ERROR_PRINT
    #define error_print(fmt, ...)\
    {\
        fprintf(\
            stderr,\
            "[ERROR] " fmt " in %s, Line %i\n",\
            __VA_ARGS__,\
            __FILE__,\
            __LINE__\
        );\
        fflush(stderr);\
    }
#else
    #define error_print(...)
#endif

/*********************************** Warning **********************************/
/**
 @details   Function for printing warning messages.
            Prints to the console the specified warning, the filename,
            and the line that triggered the warning.
            Enabled by default.
 */
#ifndef WARNING_PRINT
    #define WARNING_PRINT 1
#endif

#if WARNING_PRINT
    #define warning_print(fmt, ...)\
    {\
        fprintf(\
            stdout,\
            "[WARNING] " fmt " in %s, Line %i\n",\
            __VA_ARGS__,\
            __FILE__,\
            __LINE__\
        );\
        fflush(stdout);\
    }
#else
    #define warning_print(...)
#endif

/************************************ Info ************************************/
/**
    @details    Function for printing information messages.
                Prints information necessary for debugging to the console.
                Disabled by default.
 */
#ifndef INFO_PRINT
    #define INFO_PRINT 0
#endif

#if INFO_PRINT
    #define info_print(fmt, ...)\
    {\
        fprintf(stdout, "[INFO] " fmt "\n", __VA_ARGS__);\
        fflush(stdout);\
    }
#else
    #define info_print(...)
#endif

/******************************************************************************/
#endif /* !LOGGER_H */
