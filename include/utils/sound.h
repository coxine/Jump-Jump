#ifndef INCLUDE_UTILS_SOUND_H_
#define INCLUDE_UTILS_SOUND_H_

#include <common.h>

#define MIXER_HANDLE_ERROR(error)                                    \
    printf("msg: %s! SDL_mixer Error: %s\n", error, Mix_GetError()); \
    exit(EXIT_FAILURE);

#define WAITING_TIME 100

#define CHUNK_BEST "../static/audio/Best.mp3"
#define CHUNK_GOOD "../static/audio/Good.mp3"
#define CHUNK_NAIVE "../static/audio/Naive.mp3"
#define CHUNK_IMPROVE_LEVEL "../static/audio/ImproveLevel.mp3"
#define CHUNK_EXCITED "../static/audio/Excited.mp3"
#define CHUNK_SILENT_FORTUNE "../static/audio/SilentFortune.mp3"

void PlayChunk(char *address);
Uint32 getChunkTimeMilliseconds(Mix_Chunk *chunk);

#endif