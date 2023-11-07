#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Rus");
	std::string cipher;
	std::string text;

	std::cout << "Введите текст для шифрования" << '\n';
	std::getline(std::cin, text);

	int i{};
	bool b = false;

	while (i < text.size()) {
		int count{};
		for (; isalpha(int(text[i]));) {
			count++;
			i++;
		}

		for (int q = i - count; q < i; ++q) {
			if (text[q] + count < 'A' || text[q] + count > 'Z' || text[q] + count < 'a' || text[q] + count > 'z') {
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
			cipher += text[q] + count;
		}

		for (; !isalpha(int(text[i])); ) {
			if (text[i] == '\0') {
				b = true;
				break;
			}
			cipher += text[i];
			i++;
		}

		if (b) {
			break;
		}
	}

	std::cout << cipher;
}