// See https://aka.ms/new-console-template for more information

using CppSharp;
using CppSharp.AST;
using CppSharp.Generators;
using CppSharp.Generators.CSharp;
using CppSharp.Parser.AST;
using CppSharp.Passes;
using CppSharp.Types;
using ASTContext = CppSharp.AST.ASTContext;
using BuiltinType = CppSharp.AST.BuiltinType;
using PrimitiveType = CppSharp.AST.PrimitiveType;
using Template = CppSharp.AST.Template;
using TemplateSpecializationType = CppSharp.AST.TemplateSpecializationType;
using TranslationUnit = CppSharp.AST.TranslationUnit;
using Type = CppSharp.AST.Type;

namespace SpineCppGenBindings;


public class DllPluginTypeMap : TypeMap
{
    public override bool IsIgnored
    {
        get { return false; }
    }

    public override Type CSharpSignatureType(TypePrinterContext ctx)
    {
        return base.CSharpSignatureType(ctx);
    }
}


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

    private string _spineCppFileDir;

    private string SpineCppFileDir
    {
        get
        {
            if (string.IsNullOrEmpty(_spineCppFileDir))
            {
                var curDir = new DirectoryInfo(Directory.GetCurrentDirectory());
                _spineCppFileDir = curDir.Parent.Parent.Parent.Parent.Parent.FullName +
                                   "\\CppPlugin\\DLLPlugin\\spine-runtimes\\spine-cpp\\spine-cpp\\src\\spine";
            }

            return _spineCppFileDir;
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
                             "\\UnityCppTest\\Assets\\Scripts\\Spine\\Runtime\\spine-unity\\spine_cpp_bindings\\gen";
            }

            return _outputDir;
        }
    }

    public void Preprocess(Driver driver, ASTContext ctx)
    {
        
        ctx.IgnoreClassField("","");
        
        ctx.IgnoreHeadersWithName("ContainerUtil"); //生成报错
        ctx.IgnoreHeadersWithName("MathUtil"); //生成报错
            
        //这几个会导致生成泛型的重复，暂时不知道怎么结局
        ctx.IgnoreClassMethodWithName("Vector","add");
        ctx.IgnoreClassMethodWithName("Vector","setSize");
        ctx.IgnoreClassMethodWithName("Vector","buffer");
       
        // ctx.IgnoreClassWithName("SpineExtension");
        // ctx.IgnoreClassWithName("DefaultSpineExtension");
        // ctx.IgnoreClassWithName("SpineObject");
        // ctx.IgnoreClassWithName("String");
        // ctx.IgnoreClassWithName("Vector");
        // ctx.IgnoreClassWithName("HashMap");
        // ctx.IgnoreClassWithName("RTTI");
        // ctx.IgnoreClassWithName("Json");
        // ctx.IgnoreClassWithName("IHasRendererObject");
        // ctx.IgnoreClassWithName("PathConstraintPositionTimeline");
        //
        // ctx.IgnoreFunctionWithName("IHasRendererObject");

        // ctx.TranslationUnits.Add(new TranslationUnit());
        //
        // var templateSpecialization = new TemplateSpecializationType
        // {
        //     Template = Template(DeclarationKind.ClassTemplate, "YourGenericClass", module),
        //     Arguments = new Type[] { new BuiltinType(PrimitiveType.Int) } // 指定泛型参数类型
        // };
    }

    public void Postprocess(Driver driver, ASTContext ctx)
    {
    }

    private void CleanFiles()
    {
        var dirInfo = new DirectoryInfo(CSharpCodeOutputDir);
        foreach (var fileInfo in dirInfo.GetFiles())
        {
            File.Delete(fileInfo.FullName);
        }
    }

    public void Setup(Driver driver)
    {
        CleanFiles();
    
    
        var options = driver.Options;
        
        options.GenerateClassTemplates = true;
        // options.GenerationOutputMode = GenerationOutputMode.FilePerUnit;//生成多个文件
        options.GeneratorKind = GeneratorKind.CSharp;
        options.OutputDir = CSharpCodeOutputDir;
        var module = options.AddModule("spine_cpp");
        module.IncludeDirs.Add(SpineIncludeDir);
        module.Headers.Add("spine/spine.h");
        module.Headers.Add("spine/dll.h");
        module.Defines.Add("_WIN32");
        // module.Defines.Add("CS_CONSTRAINT");
        
        // module.Defines.Add("CPPSHARP");//防止重复生成的泛型
        // module.LibraryName = "DLLPlugin";
        
        
        // module.LibraryDirs.Add(SpineDllDir);
        // module.Libraries.Add("DLLPlugin.dll");

        foreach (var fileInfo in new DirectoryInfo(SpineCppFileDir).GetFiles())
        {
            var translationUnit = new TranslationUnit(fileInfo.FullName);
            translationUnit.Module = module;
            module.Units.Add(translationUnit);
        }
        // module.ExternalClassTemplateSpecializations.Add();
        // module.LibraryDirs.Add(@"C:\Sample\lib");
        // module.Libraries.Add("Sample.lib");
    }

    public void SetupPasses(Driver driver)
    {
        driver.AddTranslationUnitPass(new DelegatesPass());
    }
}

static class Program
{
    static void Main()
    {
        ConsoleDriver.Run(new SpineCppLibrary());
    }
}