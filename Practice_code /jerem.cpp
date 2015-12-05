#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

    //new variable type TestClass
class TestClass {
    public:
        TestClass() {
            //constructor - initialization
        }

        ~TestClass() {
            //destructor - deinitialization
        }

        void testFunc() {
            cout << "testFunc" << endl;
//	  continuous loop of TestFunc
//            TestClass x;
//            x.testFunc();
        }

    private:
};

int fibonacci(int x);

int main(int argc, char * argv[]) {
    cout << "There are " << argc << " arguments" << endl << endl;

    for (int i = 0; i < argc; i++) {
        cout << i + 1 << ": " << argv[i] << endl;
    }

    cout << endl;

    //new variable type-TestClass - name of variable =myclass
    TestClass myClass;
    myClass.testFunc();

    cout << "Fibonacci = " << fibonacci(5) << endl;
return 0;
}

int fibonacci(int x) {
    if ((x == 0) || (x == 1)) {
        return 1;
    }
    else {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
}
