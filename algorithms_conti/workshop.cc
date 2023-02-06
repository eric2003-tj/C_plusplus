#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
static std::mt19937 mt;
namespace exercises {
    int get_num() {
        std::uniform_int_distribution<int> ud(0, 1000);
	    return ud(mt);
	}
}
using namespace std;
template<class T>
void print(const vector<T> &data){
    for(auto v:data){
        cout << v << endl;
    }
}
int main(){
    vector<int> vec(10);
    // 1.Fill a vector with 10 random integers between 0 and 1000
    std::generate_n(begin(vec),10,exercises::get_num);
    // 2.Print out the vector elements
    print(vec);
    // 3.Find the maximum element in this vector
    auto max_num = max_element(cbegin(vec), cend(vec));
    cout << *max_num << endl;
    // 4.Find the index of this maximum element
    cout << distance(cbegin(vec),max_num) << endl; // index
    auto sum = accumulate(cbegin(vec),cend(vec),0);
    // 5.Sum the elements of the vector
    cout << sum << endl;
    vector<int> vec2;
    copy_if(cbegin(vec),cend(vec),back_inserter(vec2),[](int n){return (n%2==1);});
    // 6.Count the number of odd numbers in the vector
    cout << vec2.size() << endl;
    vector<double> vec3;
    // 7.Normalize the vector (divide all the elements by the largest) and put the normalized elements into a vector of doubles, without setting the size of the output vector first
    transform(cbegin(vec),cend(vec),back_inserter(vec3),[max_num](int n){return (double)n/(*max_num);});
    print(vec3);
    vector<int> copy_item;
    copy(cbegin(vec),cend(vec),back_inserter(copy_item));
    sort(begin(copy_item),end(copy_item));
    auto target = std::upper_bound(cbegin(copy_item),cend(copy_item),455);
    // 8.Make a sorted copy of the vector. Without using a functor or a lambda (or equivalent), find the first element greater than 455 and the number of elements > 455
    cout << *target << endl;
    // 9.Copy all the odd numbers to a vector of doubles, without setting the size of the output vector first
    vector<double> vec4;
    transform(cbegin(vec2),cend(vec2),back_inserter(vec4),[](int n){return (double)n;});
    // 10.Sort the vector in descending order
    sort(begin(vec),end(vec),[](int m,int n){return (m>n);});
    print(vec);
    // 11.shiffle
    shuffle(begin(vec)+1, end(vec)-1, mt);
    print(vec);
    // 12.Remove all the odd numbers from the vector
    auto defunct = remove_if(begin(vec),end(vec),[](int m){return (m%2==1);});
    vec.erase(defunct,end(vec));
    print(vec);
    // q13 Write the remaining elements to a text file on a single line as a comma separated list, without a trailing comma
    ofstream ofile{"target.txt"};
    if(ofile){
        for(auto v:vec){
            ofile << v << ",";
        }
        ofile.close();
    }
    // q14 Read a file of words and display each word once. Ignore punctuation and capitalization
    ifstream ifile{"input.txt"};
    vector<string> vec5;
    if(ifile){
        string text = "";
        while(ifile >> text){
            if(!isalnum(text[0])){
                text = text.substr(1);
            }else{
                text[0] = tolower(text[0]);
            }
            if(!isalnum(text[text.size()-1])){
                text.erase(text.size()-1);
            }
            vec5.push_back(text);
        }

		// q15 Count the total number of words in the file
        cout << vec5.size() << endl;
    }
    ifstream ifile2{"input.txt"};
    if(ifile2){
        istreambuf_iterator<char> iit{ifile2};
        istreambuf_iterator<char> eof;
		string text2{iit, eof};
		auto nlines = count(cbegin(text2), cend(text2), '\n');
		// q16  Count the number of lines in the file
        cout << nlines << endl;
        // q17
        cout << text2.size() << endl;
    }
    // q18
    ifstream ifile3{"input2.txt"};
    vector<string> vec6;
    if(ifile3){
        string text = "";
        while(ifile3 >> text){
            if(!isalnum(text[0])){
                text = text.substr(1);
            }else{
                text[0] = tolower(text[0]);
            }
            if(!isalnum(text[text.size()-1])){
                text.erase(text.size()-1);
            }
            vec6.push_back(text);
        }
    }
    int range = (vec5.size() >= vec6.size())? vec6.size():vec5.size();
    int counts = 0;
    for(int i=0;i<range;i++){
        if(vec5[i]!=vec6[i]){
            counts++;
        }
    }
    counts += fabs(vec6.size()-vec5.size());
    cout << counts << endl;
    // q19
    vector<int> factorial(6);
	iota(factorial.begin(), factorial.end(), 1);
	cout << accumulate(factorial.begin(), factorial.end(), 1,
											[] (int a, int b) { return a*b; }); //overload
}
