//
// Created by lindsey on 2021/8/8.
//

#include <iostream>

using namespace std;

class String {
private:
    char value[100];
    int length;
public:
    String();
    String(char *chs);
    int indexOf(String *str);
    int len();
    int kmp(String *str);
    ~String();
    char charAt(int i);
    void getNext(String *str,int arr[]);
    String operator+(const String &c);
    bool operator>(const String &c);
    bool operator<(const String &c);
    bool operator==(const String &c);
    friend ostream& operator<<(ostream& out,String &c);
    static int compare(String *s, String *t);
    static int strlen(String *str);
};

ostream& operator<<(ostream& out,String &c){
    out << c.value;
    return out;
}

char String::charAt(int i) {
    return value[i];
}

inline String String::operator+(const String &c) {
    char newVal[length + c.length];
    for (int i = 0; i < length; i++) {
        newVal[i] = value[i];
    }
    for (int i = 0; i < c.length; i++) {
        newVal[length + i] = c.value[i];
    }
    return String(&newVal[0]);
}

String::String(char *chs) {
    int i = 0;
    while (chs[i] != '\0') {
        value[i] = chs[i];
        i++;
    }
    value[i] = '\0';
    length = i;
}

String::String() {
    length = 0;
    value[0] = '\0';
}


int String::indexOf(String *str) {
    return kmp(str);
}

/**
 * ggggggg
 * a
 * @param str
 * @return
 */

int String::kmp(String *str) {
    int len = str->len();
    char *matStr = str->value;
    int next[len];
    for(int i = 0; i < len; i++){
        next[i] = 0;
    }
    getNext(str,next);
    int i = 0;
    int j = 0;
    while(i < length && j < len){
        if(j == -1 || value[i] == matStr[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == len){
        return i - j;
    }
    return -1;
}


String::~String() {

}

int String::len() {
    return this->length;
}


/**
 * ogoogoo
 * @param str
 * @param next
 */
void String::getNext(String *str,int next[]) {
    int len = String::strlen(str);
    next[0] = -1;
    next[1] = 0;
    int k = 0;
    for(int i = 2; i < len; i++){
        if(str->charAt(i) == str->charAt(k)){
            next[++i] = ++k;
        }else{
            k = next[i];
        }
    }
}

int String::compare(String *s, String *t) {
    int i = 0;
    while (i < s->length && i < t->length) {
        int c1 = (s->value[i]);
        int c2 = (t->value[i]);
        if (c1 > c2) {
            return 1;
        } else if (c1 < c2) {
            return -1;
        }
        if (c1 == c2) {
            i++;
            continue;
        }
    }
    if (s->length > t->length) {
        return 1;
    } else if (s->length < t->length) {
        return -1;
    } else {
        return 0;
    }
}

int String::strlen(String *str) {
    char *c = str->value;
    int i = 0;
    while(c[i] != '\0'){
        i++;
    }
    return i;
}