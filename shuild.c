#define SHU_IMPLEMENTATION
#include "shu/shu.h"
#include "shu/shuild.h"

#define CHAPTER_COUNT 7
#define SOURCE_DIR "exercises/"
#define OUTPUT_DIR "build/"

void ForEachExerciseFile(const char *path, SHUFileType type, void *data)
{
    if (type != SHUFileType_Regular)
    {
        return;
    }

    usz pathLength = strlen(path);
    SHUSlice moduleName = cs(path, pathLength - 2);
    for (usz i = pathLength - 1; i >= 0; i--)
    {
        if (path[i] == SHUM_PATH_SEPARATOR)
        {
            moduleName = cs(path + i + 1, pathLength - i + 1 - 2);
            break;
        }
    }

    SHU_LogInfo("%s", SHU_UtilFormat("%.*s", (usz)path - (usz)moduleName.data, path));

    // SHU_MODULE(SHU_UtilFormat("%.*s", moduleName.size, moduleName.data), SHU_UtilFormat("%.*s", (usz)path - (usz)moduleName.data, path), SHUModuleType_Executable, OUTPUT_DIR)
    {
    }
}

int main(int argc, char **argv)
{
    SHU_CompilerConfigureTry(NULL);

    SHU_UtilListDirectory(SOURCE_DIR, true, ForEachExerciseFile, NULL);
    return 0;
}
