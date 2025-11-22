/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:09:03 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 12:58:07 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	//check args
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return EXIT_FAILURE;
	}

	//handle params
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	//check empty strings
	if (filename.empty() || s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return EXIT_FAILURE;
	}

	//open in file
	std::ifstream	inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return EXIT_FAILURE;
	}

	//create out file
	std::ofstream	outFile((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Cannot create file " << filename << ".replace" << std::endl;
		inFile.close();
		return EXIT_FAILURE;
	}

	//handle
	std::string	content;
	std::string	line;
	while (std::getline(inFile, line))
	{
		content +=line;
		if (!inFile.eof())
			content += '\n'; // возвращаем перенос строки, который убирает getline
	}
	inFile.close();

	std::string	result;
	size_t	pos = 0;
	size_t	found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content.substr(pos, found - pos)); //всё до s1
		result.append(s2);				 // вместо s1
		pos = found + s1.length();                       // сдвиг
	}
	result.append(content.substr(pos)); // остаток текста
	outFile << result;
	outFile.close();

	/* OR
	// Обработка файла построчно
	std::string line;
	while (std::getline(inputFile, line)) {
        size_t pos = 0;
        size_t found = 0;
        std::string result;
        
        // Поиск и замена всех вхождений s1
        while ((found = line.find(s1, pos)) != std::string::npos) {
            // Добавление части до найденной подстроки
            result += line.substr(pos, found - pos);
            // Добавление замены
            result += s2;
            // Пропуск замененной подстроки
            pos = found + s1.length();
        }
        // Добавление остатка строки
        result += line.substr(pos);
        
        // Запись в выходной файл
        outputFile << result << std::endl;
    }
	*/
	return EXIT_SUCCESS;
}
