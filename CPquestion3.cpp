/*Q}
Sanjay and Harsh go to a wedding reception party. Harsh and sanjay both are foodie boys. But harsh is more foodie than sanjay. They both usually visit receptions only to enjoy delecious foods out there. Harsh is very specific about his chioce and he is having an injury in his leg too. So, he can't go to the stall for taking plate for him. Sanjay is very innocent boy, so he helps Harsh. Harsh asks sanjay to take blue colour plate for him.
Since Harsh is very specific about his choice, he won't eat untill he will not be getting plate of his colour. Sanjay goes to the stall and he saw that plates were arranged such that he can only take the plate at the top.
Sanjay does not understand colors. So, he takes one plate on the top and ask to harsh, is that your plate? If plate is of Harsh choice, then he says yes, otherwise says no. If Harsh says no, then sanjay takes the plate and put it on the other side.
Your task is to determine whether harsh will eat food or not. Also how many plates sanjay put either side when searching for harsh's plate.
Input Format
1.	N integer, as the number of plates on the stall
2.	colors of N plates, last one is like on the top
3.	a sequence S, colour of plates
4.	color name that Harsh demands
Constraints
0<=N<=2*10^9
Output Format
1.	In first line print whether harsh gets his plate (YES or NO)
2.	In second line print number of plates Sanjay kept on other side
Sample Input 0
3
red green orange
red
Sample Output 0
YES
2
Explanation 0
The plates on the stoll will be orange->green->red, sanjay look at the peak, he got orange, it is not red, so harsh rejects it and sanjay puts on other side. Now gets orange and puts other side, but now gets red. so he got harsh choice that's why print "YES" and on other side there are 2 plates.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, count=0;
    cin>>n;
    string s[n];
    string st;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>st;
    for(int i=n-1;i>=0;i--){
        if(s[i]==st){
            cout<<"YES"<<endl;
            cout<<count;
            return 0;
        }
        count++;
        
    }
    cout<<"NO"<<endl;
    cout<<count<<endl;
    return 0;
}
