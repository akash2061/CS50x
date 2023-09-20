#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t byte;

void check(int argc);
void checkfile(FILE *file);
int isjpeg(byte buffer[]);
int main(int argc, char *argv[])
{
    check(argc);
    FILE *raw = fopen(argv[1], "r");
    checkfile(raw);

    int jpegCount = 0;
    FILE *jpegFile = NULL;

    while (1)
    {
        byte buffer[BLOCK_SIZE];
        size_t bytesRead = fread(buffer, sizeof(byte), BLOCK_SIZE, raw);

        if (bytesRead == 0 && feof(raw))
            break;

        if (isjpeg(buffer))
        {

            if (jpegFile != NULL)
                fclose(jpegFile);

            char filename[8];
            sprintf(filename, "%03d.jpg", jpegCount++);
            jpegFile = fopen(filename, "w");
            if (jpegFile == NULL)
            {
                fprintf(stderr, "Could not create %s\n", filename);
                return 3;
            }
        }

        if (jpegFile != NULL)
        {
            fwrite(buffer, sizeof(byte), bytesRead, jpegFile);
        }
    }

    if (jpegFile != NULL)
        fclose(jpegFile);

    fclose(raw);
}
void check(int argc)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        exit(1);
    }
}

void checkfile(FILE *file)
{
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        exit(2);
    }
}

int isjpeg(byte buffer[])
{
    return (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0);
}