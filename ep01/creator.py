#import
import os
import getpass
#main
print(os.getcwd())
path = os.getcwd()
path = path +"/"
#path = '/Users/' + username + '/'+"Documents"+ '/'

print("Hello there! What do you wish to do? ")
print("1) Create a Project ")
print("2) Add a new class to your project")
imp = input()

if (imp == '1'):
    name = input("Name your project:")

    try:
        path = '/Users/' + username +"Documents"
        path = path + name + "/"
        print(path)
        os.mkdir(path)
    except:
        pass
    nameWrite = path + name + ".cpp"
    fwrite = open(nameWrite,"w")
    fwrite.write("#include <iostream>\n\n")
    fwrite.write("using namespace std;\n")
    fwrite.write("    int main() {\n")
    fwrite.write('      cout << "Hello, World! " <<endl;\n')
    fwrite.write("      return (0);\n")
    fwrite.write("}\n")
    fwrite.close()
if (imp == '2'):
    #name = input("What's the name of your project?")
    #path = '/Users/' + username +"Documents"
    #path = path + name + "/"
    #print(path)
    #try:
    #    fname = path +name +".cpp"
        #fhandle = open(fname)
#    except:
        #print("ERROR")
        #quit()
    #t = list()
    #for lines in fhandle:
    #    t.append(lines)
    #fhandle.close()
    className = input("What's the name of your class?")
    wname = path + className +".cpp"
    fwrite = open(wname,"w")
    print(className)
    st = ('''#include "%s.h"

    %s::%s() {
        //ctor
    }

    %s::~%s() {
        //dtor
    }

    '''% (className, className, className, className, className))
    fwrite.write(st)
    fwrite.close()





    wname = path + className +".h"
    fwrite = open(wname,"w")
    Hclassname = className.upper()
    st = ('''#ifndef %s_H
    #define %s_H


    class %s {
        public:
            %s();
            virtual ~%s();

        protected:

        private:
    };

    #endif // %s_H

    '''%(Hclassname,Hclassname,className,className,className,Hclassname))
    fwrite.write(st)
    fwrite.close()
