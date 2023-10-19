typedef  int (*CSharpFunction)(int a, float b);
extern "C" {


	CSharpFunction csharpFunc;

	void Init(CSharpFunction f) {
		csharpFunc = f;
	}

	void Foo() {
		int retVal = csharpFunc(1, 2.22f);
	}
}