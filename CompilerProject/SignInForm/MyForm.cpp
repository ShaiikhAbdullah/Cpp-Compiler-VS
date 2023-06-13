//#include "MyForm1.h"
#include "MyForm.h"

// -- Driver Program
[STAThreadAttribute]
int main() {

    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    SignInForm::MyForm form;
    Application::Run(% form);
    return 0; // Add a return statement to indicate successful execution

}