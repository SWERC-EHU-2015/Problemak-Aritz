#include <iostream>
#include <string>

using namespace std;

bool isEnd(const char &c)
{
	return c == '*' || c == '[' || c == '&' || c == ' ' || c == ';' || c == ',';
}

int main()
{
	string s;
	bool veryFirst = true;
	while (static_cast<bool>(getline(cin, s)))
	{
		int i = 0;

		while (i < s.length() && !isEnd(s[i])) ++i;
		string typeName = s.substr(0, i);

		int commonBegin = i;

		while (i < s.length() && s[i] != ' ') ++i;

		string commonOperators = s.substr(commonBegin, i - commonBegin);
		i++;

		bool first = true;

		while (i < s.length() && s[i] != ';')
		{
			if (first && !veryFirst) cout << endl;
			veryFirst = false;
			first = false;
			int beginName = i;
			while (i < s.length() && !isEnd(s[i])) ++i;
			string varName = s.substr(beginName, i - beginName);

			string varOperators("");
			for (; i < s.length() && s[i] != ',' && s[i] != ';'; ++i)
			{
				if (s[i] == '&' || s[i] == '*')
				{
					varOperators = s[i] + varOperators;
				}
				else if (s[i] == '[')
				{
					varOperators = "[]" + varOperators;
					i++; // Skip ']'
				}
			}
			cout << typeName << commonOperators << varOperators << " " << varName << ";" << endl;
			if (s[i] == ',')
				i += 2;
		}
	}
	return 0;
}
