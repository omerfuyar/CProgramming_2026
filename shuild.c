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

    SHU_LogInfo("'%s'", path);

    const char *sourceName = SHUI_PathFileName(path);
    char *rootDir = SHUI_PathDirectory(path);
    char *moduleName = SHU_UtilFormat("%.*s", strlen(sourceName) - 2, sourceName);
    char *outputDir = SHUI_PathJoinDirectory("build", rootDir);

    SHU_Module(moduleName,
               rootDir,
               SHUModuleType_Executable,
               outputDir)
    {
        SHU_ModuleAddSourceFiles(sourceName);
    }

    free(rootDir);
    free(moduleName);
    free(outputDir);
}

int main(int argc, char **argv)
{
    SHU_CompilerConfigureTry(NULL);

    SHU_UtilListDirectory(SOURCE_DIR, true, ForEachExerciseFile, NULL);
    return 0;
}
