#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include<vector>
#include<fstream>

using namespace std;
int inputSelection;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;
	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}
//part one create a display menu

//this route did not work. 
//void listViewer() {
	//CallProcedure("WordCount");
	/*vector<string> lines;
	ifstream myFS;
	myFS.open("InputFile.txt", ios::in);//read
	string items;
	if (myFS.is_open()) {
		while (getline(myFS, items)) {
			lines.push_back(items);
				 callIntFunc("WordCount", lines.back());
				 CallProcedure("WordCount");
		}}
			myFS.close();*/	
		//}

void selectionOne() {
	//listViewer();
	CallProcedure("WordCount");
	//selection one will give a count of how many times a product repeats 

}
void selectionTwo() {
	//CallProcedure("ItemSearch");
	//input for the itemSearch function
	string v;
	cout << "Enter item Search: ";
	cin >> v;
	callIntFunc("ItemSearch", v);

}
void selectionThree() {
	cout << "will Display a histagram of purchases"<<endl;
	CallProcedure("displayHistogram");
		//cout << callIntFunc("displayHistagram");

}
void mainMenu() {
	cout << "Selections input" << endl;
	cout << "1: selection 1" << endl;
	cout << "2: selection 2" << endl;
	cout << "3: selection 3" << endl;
	cout << "4: Quit Selection" << endl;
	while (true) {
		cout << "Enter your selection: ";
		cin >> inputSelection;

		switch (inputSelection) {
		case 1:
			selectionOne();
			break;
		case 2:
			selectionTwo();
			break;
		case 3:
			selectionThree();
			break;
		case 4:
			exit(false);
		default:
			break;
		}
	}

}

int main()
{
	mainMenu();
	
	//menu functionality that will recognize user input.
	
		
	
	
	//CallProcedure("printsomething");
	/*cout << callIntFunc("PrintMe", "House") << endl;
	cout << callIntFunc("SquareValue", 2);*/

}