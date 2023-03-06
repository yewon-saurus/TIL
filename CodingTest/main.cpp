#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    vector<int> v = {1, 2, 3};

    /*
        아놔.. ㅋㅋ
        vscode 터미널에서
        vector같은 STL이 포함된 cpp 파일을 컴파일 해 산출된 실행파일이
        실행은 되는데 오류 로그도 없고 실행 결과도 출력되지 않아서
        한참을 삽질 했는데..
        Windows Terminal 에서 똑같은 파일 실행해보니
        정상적으로 출력 되네요 ^^
    */

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        cout << " hi" << i << endl;
    }

    return 0;
}