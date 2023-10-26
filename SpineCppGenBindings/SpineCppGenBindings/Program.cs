// See https://aka.ms/new-console-template for more information

using CppSharp;
using CppSharp.AST;
using CppSharp.Generators;

namespace SpineCppGenBindings;

class SpineCppLibrary : ILibrary
{
    private string _spineIncludeDir = "";

    private string SpineIncludeDir
    {
        get
        {
            if (string.IsNullOrEmpty(_spineIncludeDir))
            {
                var curDir = new DirectoryInfo(Directory.GetCurrentDirectory());
                _spineIncludeDir = curDir.Parent.Parent.Parent.Parent.Parent.FullName +
                                   "\\CppPlugin\\DLLPlugin\\spine-runtimes\\spine-cpp\\spine-cpp\\include";
            }

            return _spineIncludeDir;
        }
    }

    private string _spineDllDir = "";

    private string SpineDllDir
    {
        get
        {
            if (string.IsNullOrEmpty(_spineDllDir))
            {
                var curDir = new DirectoryInfo(Directory.GetCurrentDirectory());
                _spineDllDir = curDir.Parent.Parent.Parent.Parent.Parent.FullName +
                               "\\DLLExportDir";
            }

            return _spineDllDir;
        }
    }

    private string _outputDir = "";

    private string CSharpCodeOutputDir
    {
        get
        {
            if (string.IsNullOrEmpty(_outputDir))
            {
                var curDir = new DirectoryInfo(Directory.GetCurrentDirectory());
                _outputDir = curDir.Parent.Parent.Parent.Parent.Parent.FullName +
                             "\\UnityCppTest\\Assets\\Scripts\\App\\CppPlugin\\SpineCppProxy";
            }

            return _outputDir;
        }
    }

    public void Preprocess(Driver driver, ASTContext ctx)
    {
        ctx.IgnoreHeadersWithName("ContainerUtil");
        ctx.IgnoreHeadersWithName("MathUtil");

        ctx.IgnoreClassWithName("SpineExtension");
        ctx.IgnoreClassWithName("DefaultSpineExtension");
        ctx.IgnoreClassWithName("SpineObject");
        ctx.IgnoreClassWithName("String");
        ctx.IgnoreClassWithName("Vector");
        ctx.IgnoreClassWithName("HashMap");
        
        ctx.ignore("Pool");
        
        ctx.IgnoreClassWithName("IHasRendererObject");
        ctx.IgnoreFunctionWithName("IHasRendererObject");
    }

    public void Postprocess(Driver driver, ASTContext ctx)
    {
    }

    public void Setup(Driver driver)
    {
        var options = driver.Options;
        options.GeneratorKind = GeneratorKind.CSharp;
        options.OutputDir = CSharpCodeOutputDir;
        var module = options.AddModule("spine_cpp");
        module.IncludeDirs.Add(SpineIncludeDir);
        module.Headers.Add("spine/spine.h");
        module.Headers.Add("spine/dll.h");
        module.Defines.Add("_WIN32");
        module.LibraryDirs.Add(SpineDllDir);
        module.Libraries.Add("DLLPlugin.dll");

        // module.LibraryDirs.Add(@"C:\Sample\lib");
        // module.Libraries.Add("Sample.lib");
    }

    public void SetupPasses(Driver driver)
    {
    }
}

static class Program
{
    static void Main()
    {
        ConsoleDriver.Run(new SpineCppLibrary());
    }
}