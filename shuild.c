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
    SHUSlice sourceName = cs((char *)path, pathLength - 4);
    for (usz i = pathLength - 1; i >= 0; i--)
    {
        if (path[i] == SHUM_PATH_SEPARATOR)
        {
            sourceName = cs((char *)path + i + 1, pathLength - i - 1);
            break;
        }
    }

    const char *moduleName = SHU_UtilFormat("%.*s", sourceName.size - 2, sourceName.data);
    const char *sourceNameStr = SHU_UtilFormat("%.*s", sourceName.size, sourceName.data);
    const char *moduleRoot = SHU_UtilFormat("%.*s", pathLength - sourceName.size - 1, path);

    SHU_LogInfo("'%s'", moduleName);
    SHU_LogInfo("'%s'", moduleRoot);

    SHU_MODULE(moduleName,
               moduleRoot,
               SHUModuleType_Executable,
               SHU_UtilFormat("%s%s", OUTPUT_DIR, moduleRoot))
    {
        SHU_ModuleAddSourceFiles(sourceNameStr);
    }
}

int main(int argc, char **argv)
{
    SHU_CompilerConfigureTry(NULL);

    SHU_UtilListDirectory(SOURCE_DIR, true, ForEachExerciseFile, NULL);
    return 0;
}
