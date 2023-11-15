#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using std::string;

int main()
{
	std::ifstream file("src/test.txt");
	string code;
//why does ifstream begin in root folder
	if(!file)
	{
		std::cout << "Failed to open src/test.txt";
		return 1;
	}
	std::stack<float> ram;
	//code sto- borrowed from https://www.tutorialspoint.com/Read-whole-ASCII-file-into-Cplusplus-std-string
	std::ostringstream ss;
    ss << file.rdbuf(); // reading data
    code = ss.str();
	
	//code from chatgpt
	std::istringstream iss(code);
	std::string line;
    const int MAX_LINES = 100; // Maximum number of lines
    const int MAX_WORDS_PER_LINE = 50; // Maximum number of words per line
    std::string lines[MAX_LINES][MAX_WORDS_PER_LINE];
    int lineCount = 0;

    while (std::getline(iss, line) && lineCount < MAX_LINES) {
        std::istringstream lineStream(line);
        std::string word;
        int wordCount = 0;
        while (lineStream >> word && wordCount < MAX_WORDS_PER_LINE) {
            lines[lineCount][wordCount++] = word;
        }
        ++lineCount;
    }

    // Output the lines and words
    for (int i = 0; i < lineCount; ++i) {
        for (int j = 0; lines[i][j] != ""; ++j) {
            if(lines[i][j] == "push")
			{
				ram.push(stoi(lines[i][j+1]));
				j++;
			}
			if(lines[i][j] == "pop")
			{
				ram.pop();
			}
			if(lines[i][j] == "print")
			{
				std::cout << ram.top();
			}
			
			//add
			if(lines[i][j] == "add")
			{
				int num1 = ram.top();
				ram.pop();
				int num2 = ram.top();
				ram.push(num1+num2);
				//probably not a good way of doing this
				
			}
			if(lines[i][j] == "add2")
			{
				int num1 = stoi(lines[i][j+1]);
				int num2 = stoi(lines[i][j+2]);
				ram.push(num1+num2);
				j+=2;
				//which way is better?
				
			}
			
			//sub
			if(lines[i][j] == "sub")
			{
				int num1 = ram.top();
				ram.pop();
				int num2 = ram.top();
				ram.push(num1-num2);
				//probably not a good way of doing this
				
			}
			if(lines[i][j] == "sub2")
			{
				int num1 = stoi(lines[i][j+1]);
				int num2 = stoi(lines[i][j+2]);
				ram.push(num1-num2);
				j+=2;
				//which way is better?
				
			}
			
			//mul
			if(lines[i][j] == "mul")
			{
				int num1 = ram.top();
				ram.pop();
				int num2 = ram.top();
				ram.push(num1*num2);
				//probably not a good way of doing this
				
			}
			if(lines[i][j] == "mul2")
			{
				int num1 = stoi(lines[i][j+1]);
				int num2 = stoi(lines[i][j+2]);
				ram.push(num1*num2);
				j+=2;
				//which way is better?
			}
			
			//div
			if(lines[i][j] == "div")
			{
				int num1 = ram.top();
				ram.pop();
				int num2 = ram.top();
				ram.push(num1/num2);
				//probably not a good way of doing this
				
			}
			if(lines[i][j] == "div2")
			{
				int num1 = stoi(lines[i][j+1]);
				int num2 = stoi(lines[i][j+2]);
				ram.push(num1/num2);
				j+=2;
				//which way is better?
			}
        }
    }

	return 0;
}