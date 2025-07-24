#include <iostream>
#include <cstdlib>
// #include <ctime>
#include <string>
// #include <cctype>

using namespace std;

enum PasswordStrength
{
    WEAK,
    MODERATE,
    STRONG
};

string generatePassword(int length)
{
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";
    const int charsetSize = charset.size();

    // srand(time(0));

    string password;
    for (int i = 0; i < length; ++i)
    {
        password += charset[rand() % charsetSize];
    }

    return password;
}

PasswordStrength assessPasswordStrength(const string &password)
{
    size_t length = password.length();
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char c : password)
    {
        if (isupper(c))
        {
            hasUpperCase = true;
        }
        else if (islower(c))
        {
            hasLowerCase = true;
        }
        else if (isdigit(c))
        {
            hasDigit = true;
        }
        else if (ispunct(c))
        {
            hasSpecialChar = true;
        }
    }

    string commonPasswords[] = {"password", "123456", "qwerty", "abc123"};

    for (const string &common : commonPasswords)
    {
        if (password == common)
        {
            return WEAK;
        }
    }

    if (length < 8 || (!hasUpperCase || !hasLowerCase || !hasDigit || !hasSpecialChar))
    {
        return WEAK;
    }
    else if (length < 12 || (!hasSpecialChar))
    {
        return MODERATE;
    }
    else
    {
        return STRONG;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Generate Password\n";
        cout << "2. Check Password Strength\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int passwordLength;
            cout << "Enter the desired password length: ";
            cin >> passwordLength;

            if (passwordLength <= 0)
            {
                cerr << "Invalid password length.\n";
                break;
            }

            // Generate a password
            string generatedPassword = generatePassword(passwordLength);
            cout << "Generated Password: " << generatedPassword << endl;
            break;
        }
        case 2:
        {
            string userPassword;
            cout << "Enter your password: ";
            cin >> userPassword;

            // Assess password strength
            PasswordStrength strength = assessPasswordStrength(userPassword);

            switch (strength)
            {
            case WEAK:
                cout << "Password Strength: Weak. Consider improving it for better security.\n";
                break;
            case MODERATE:
                cout << "Password Strength: Moderate. It meets some security criteria.\n";
                break;
            case STRONG:
                cout << "Password Strength: Strong. Well done!\n";
                break;
            }
            break;
        }
        case 3:
            cout << "Exiting. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
