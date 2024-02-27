#include <iostream>

using namespace std;

int main() {
    __int16 A1, A2, A3, B1, B2, B3, C1, C2, C3;
    
    cout << "A1"<< endl;
    cin >> hex >> A1;

    cout << "A2" << endl;
    cin >> hex >> A2;

    cout << "A3" << endl;
    cin >> hex >> A3;
    //не знаю почему, но оно даёт мне ввести б1 б2 б3 через раз

    cout << "B1" << endl;
    cin >> hex >> B1;

    cout << "B2" << endl;
    cin >> hex >> B2;

    cout << "B3" << endl;
    cin >> hex >> B3;

    __asm {
        mov ax, A1
        add ax, B1
        mov C1, ax

        mov ax, A2
        adc ax, B2
        mov C2, ax

        mov ax, A3
        adc ax, B3
        mov C3, ax
    }

    cout << hex << "C1: " << C1 << endl;
    cout << hex << "C2: " << C2 << endl;
    cout << hex << "C3: " << C3 << endl;

    int64_t result = (static_cast<int64_t>(C3) << 32) | (static_cast<int64_t>(C2) << 16) | C1;
    cout << dec << result << endl;

    return 0;
}
