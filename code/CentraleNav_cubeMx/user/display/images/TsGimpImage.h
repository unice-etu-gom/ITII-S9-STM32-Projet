#ifndef TSGIMPIMAGE_H
#define TSGIMPIMAGE_H

#include <stdint.h>

/* ########################################################################## */
/* ########################################################################## */

/**
 *  @struct TsGimpImage
 *  @brief  This structure defines the content of an RGB image as exported by
 *          Gimp.
 *
 *  To convert an image to C source code using Gimp:
 *  + Open the image you want
 *  + Select "File -> Export as..."
 *  + A first pop-up appears:
 *    + Choose the destination foder & file name
 *    + Select "C source code" as the file type
 *    + Validate - A second pop-up will appear
 *  + Pop-up "Export image as C source code":
 *    + Name the structure
 *    + Untick all options, **except "Save as RGB565 (16-bit)"**
 *    + Click "OK"
 *  + The source file is generated.
 *  + For convenience, you can replace the struct declaration in the source file
 *    by the \ref TsGimpImage typedef.
 */
typedef struct {
    unsigned int    width;
    unsigned int    height;
    unsigned int    bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
    uint8_t         pixel_data[];
} TsGimpImage;

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< TSGIMPIMAGE_H */
