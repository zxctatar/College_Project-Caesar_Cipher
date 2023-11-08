#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Rus");
	std::string cipher;
	std::string text;

	std::cout << "Введите текст для шифрования" << '\n';
	std::getline(std::cin, text);

	for (int i = 0; i < text.size(); ) {
		int count{};

		for (; isalpha(int(text[i]));) {
			count++;
			i++;
		}

		for (int q = i - count; q < i; ++q) {
			char temp = text[q];
			for (int w = i - count; w < i; ++w) {
				if (!isalpha(int(temp + 1))) {
					if (temp == 'Z') {
						temp = 'A';
					}
					else {
						temp = 'a';
					}
					continue;
				}
				temp += 1;
			}
			cipher += temp;
			continue;

		}

		for (; !isalpha(int(text[i])); ) {
			if (text[i] == '\0') {
				break;
			}
			cipher += text[i];
			i++;
		}
	}

	std::cout << cipher;
}