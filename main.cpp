#include "encryption.cpp"


int PWLength = 0;   // global password length 


int main () {

    passwordEntry attempt;
    string enteredPW;
    string imagePath;
    string finalPW;

    cout << "Enter password to be encrypted: ";
    cin >> enteredPW;

    unsigned int PWArray[enteredPW.length()];   // array to store encrypted hex values
    
    cout << "Enter the name of image (within the folder /images) to be used: ";
    cin >> imagePath;

    attempt.image = imread("images/" + imagePath);

    attempt.beginProcess(enteredPW, 1);     // encrypt
    cout << "Encrypted password is: ";
    finalPW = attempt.getResult();
    for (int i = 0; i < enteredPW.length(); i++) {
        PWArray[i] = convert(finalPW[i]);
        cout << hex << PWArray[i] << dec << " ";
    }
    cout << endl;

    cout << "\nDecryption sequence: " << endl;

    attempt.beginProcess(finalPW, 0);     // decrypt
    cout << "Original values of string via decryption: ";
    finalPW = attempt.getResult();
    for (int i = 0; i < enteredPW.length(); i++) {
        PWArray[i] = convert(finalPW[i]);
        cout << hex << PWArray[i] << dec << " ";
    }
    cout << endl;

}

