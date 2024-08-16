/*Q	}
You are going to write a program that will test awareness of a user about CORONA virus precautions. A user Ui is said to be aware if he knows what precaution he has to take else he/she will said to be unaware. Valid Precautions list are provided below:
1.	Hands, wash them often INPUT CODE: "HANDS"
2.	Elbow, cough into it INPUT CODE: "ELBOW"
3.	Face, don't touch it INPUT CODE: "FACE"
4.	Space, Keep safe distance INPUT CODE: "SPACE"
5.	Feel sick? Stay home INPUT CODE: "SICK"
List of precautions will be provided as Pi that will contain CODE of precautions. Your task is to calculate awareness percentage of each user. A user is said to be aware if his awareness percentage (say X) is greater than or equal to 50:
•	i.e. X >= 50%
else user is said to be unaware.
For more information, check sample test cases.
Input Format
1.	First line will contain an integer T that denotes number of test cases.
2.	Next line of each test case will contain an integer N (number of users)
3.	For each N lines input is as follows:
•	first line will contain single string denoting name of the user
•	second line will contain an integer M (number of precautions taken)
•	next M lines will contain single word denoting precaution known to user.
Constraints
1.	1 <= T <= 100
2.	User's name will contain Single word only.
3.	1 <= N <= 10^5
4.	0 <= M <= 5
Output Format
For each test case, output one line containing Test Case #x.y: A B% C, where x is the test case number (starting from 1) , y is line number i (starting from 1 to N), B is the name of user and C is string (either AWARE or UNAWARE).
*/


#include <iostream>
using namespace std;

int main() {
    int T, N, M, i, j, k, count, b[1000];
    string a[1000], name[1000], pi[5] = {"HANDS", "ELBOW", "FACE", "SPACE", "SICK"};

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (i = 0; i < N; i++) {
            cin >> name[i];
            cin >> M;
            count = 0;

            for (j = 0; j < M; j++) {
                cin >> a[j];
                for (k = 0; k < 5; k++) {
                    if (pi[k] == a[j])
                        count++;
                }
            }
            b[i] = count * 100 / 5;
        }

        for (i = 0; i < N; i++) {
            if (b[i] >= 50) {
                cout << "Test Case #" << t << "." << i + 1 << ": " << name[i] << " " << b[i] << "%" << " AWARE" << endl;
            } else {
                cout << "Test Case #" << t << "." << i + 1 << ": " << name[i] << " " << b[i] << "%" << " UNAWARE" << endl;
            }
        }
    }

    return 0;
}
