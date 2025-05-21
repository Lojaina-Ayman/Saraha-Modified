#include "Welcome.h"
#include "Login.h"
#include "Register.h"
#include "Messages.h"
#include "Sent.h"
#include "Favourite.h"
#include "Sending.h"
#include "Profile.h"

using namespace System;
using namespace System::Windows::Forms;

enum class FormType {
    Welcome,
    Login,
    Register,
    Messages,
    Sent,
    Favourite,
    Sending,
    Profile,
    Exit
};

[STAThread]
int main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);


    FormType currentForm = FormType::Welcome;

    while (true) {
        switch (currentForm) {

        case FormType::Welcome: {
            GUI::Welcome^ welcome = gcnew GUI::Welcome();
            welcome->ShowDialog();

            if (welcome->switchToLogin)
                currentForm = FormType::Login;
            else if (welcome->switchToReg)
                currentForm = FormType::Register;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Login: {
            GUI::Login^ login = gcnew GUI::Login();
            login->ShowDialog();

            if (login->switchToMessage)
                currentForm = FormType::Messages;
            else if (login->switchToWelcome)
                currentForm = FormType::Welcome;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Register: {
            GUI::Register^ reg = gcnew GUI::Register();
            reg->ShowDialog();

            if (reg->switchToMessage)
                currentForm = FormType::Login;
            else if (reg->switchToWelcome)
                currentForm = FormType::Welcome;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Messages: {
            GUI::Messages^ msg = gcnew GUI::Messages();
            msg->ShowDialog();

            if (msg->switchToSent)
                currentForm = FormType::Sent;
            else if (msg->switchToFav)
                currentForm = FormType::Favourite;
            else if (msg->switchToSending)
                currentForm = FormType::Sending;
            else if (msg->switchToWelcome)
                currentForm = FormType::Welcome;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Sent: {
            GUI::Sent^ sent = gcnew GUI::Sent();
            sent->ShowDialog();

            if (sent->switchToMessage)
                currentForm = FormType::Messages;
            else if (sent->switchToFav)
                currentForm = FormType::Favourite;
            else if (sent->switchToSending)
                currentForm = FormType::Sending;
            else if (sent->switchToWelcome)
                currentForm = FormType::Welcome;
            else if (sent->reload)
                currentForm = FormType::Sent;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Favourite: {
            GUI::Favourite^ fav = gcnew GUI::Favourite();
            fav->ShowDialog();

            if (fav->switchToMessage)
                currentForm = FormType::Messages;
            else if (fav->switchToSent)
                currentForm = FormType::Sent;
            else if (fav->switchToSending)
                currentForm = FormType::Sending;
            else if (fav->switchToWelcome)
                currentForm = FormType::Welcome;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Sending: {
            GUI::Sending^ sending = gcnew GUI::Sending();
            sending->ShowDialog();

            if (sending->switchToMessage)
                currentForm = FormType::Messages;
            else if (sending->switchToWelcome)
                currentForm = FormType::Welcome;
            else if (sending->switchToProfile)
                currentForm = FormType::Profile;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Profile: {
            GUI::Profile^ profile = gcnew GUI::Profile();
            profile->ShowDialog();

            if (profile->switchToSending)
                currentForm = FormType::Sending;
            else if (profile->switchToWelcome)
                currentForm = FormType::Welcome;
            else
                currentForm = FormType::Exit;
            break;
        }

        case FormType::Exit:
        default:
            return 0;
        }
    }
}