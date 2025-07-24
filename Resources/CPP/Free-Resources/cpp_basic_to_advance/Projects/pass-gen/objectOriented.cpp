#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Abstract base class
class PasswordGeneratorBase
{
public:
    virtual string generatePassword(int length) = 0;
};

// Derived class implementing password generation with random characters
class RandomPasswordGenerator : public PasswordGeneratorBase
{
public:
    string generatePassword(int length) override
    {
        string allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";

        string password = "";

        // Seed for randomness
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < length; ++i)
        {
            int randomIndex = rand() % allChars.length();
            password += allChars[randomIndex];
        }

        return password;
    }
};

// Derived class implementing password generation with alphanumeric characters
class AlphanumericPasswordGenerator : public PasswordGeneratorBase
{
public:
    string generatePassword(int length) override
    {
        string alphanumericChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string password = "";

        // Seed for randomness
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < length; ++i)
        {
            int randomIndex = rand() % alphanumericChars.length();
            password += alphanumericChars[randomIndex];
        }

        return password;
    }
};

// Derived class implementing password generation with only numbers
class NumbersOnlyGenerator : public PasswordGeneratorBase
{
private:
    string numbers;

public:
    NumbersOnlyGenerator() : numbers("0123456789") {}

    string generatePassword(int length) override
    {
        string password = "";

        // Seed for randomness
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < length; ++i)
        {
            int randomIndex = rand() % numbers.length();
            password += numbers[randomIndex];
        }

        return password;
    }
};

// Derived class implementing password generation with only characters
class CharactersOnlyGenerator : public PasswordGeneratorBase
{
private:
    string characters;

public:
    CharactersOnlyGenerator() : characters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {}

    string generatePassword(int length) override
    {
        string password = "";

        // Seed for randomness
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < length; ++i)
        {
            int randomIndex = rand() % characters.length();
            password += characters[randomIndex];
        }

        return password;
    }
};

int main()
{
    RandomPasswordGenerator randomPasswordGenerator;
    AlphanumericPasswordGenerator alphanumericPasswordGenerator;
    NumbersOnlyGenerator numbersOnlyGenerator;
    CharactersOnlyGenerator charactersOnlyGenerator;

    PasswordGeneratorBase *passwordGenerator = nullptr;

    int choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Generate Random Password" << endl;
        cout << "2. Alphanumeric Password" << endl;
        cout << "3. Numbers Only" << endl;
        cout << "4. Characters Only" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            passwordGenerator = &randomPasswordGenerator;
            break;
        case 2:
            passwordGenerator = &alphanumericPasswordGenerator;
            break;
        case 3:
            passwordGenerator = &numbersOnlyGenerator;
            break;
        case 4:
            passwordGenerator = &charactersOnlyGenerator;
            break;
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            break;
        }

        if (passwordGenerator != nullptr && choice != 5)
        {
            int passwordLength;
            cout << "Enter the desired length of the password: ";
            cin >> passwordLength;

            string generatedPassword = passwordGenerator->generatePassword(passwordLength);
            cout << "Generated Password: " << generatedPassword << endl;
        }

    } while (choice != 5);

    return 0;
}
