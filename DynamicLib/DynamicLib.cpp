#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
extern "C" __declspec(dllexport) bool FindAllChars(const char* str, const char* target) {
    vector<char> targetChars(target, target + strlen(target));
    for (char c : targetChars) {
        if (find(str, str + strlen(str), c) == str + strlen(str)) {
            return false;
        }
    }
    return true;
}
