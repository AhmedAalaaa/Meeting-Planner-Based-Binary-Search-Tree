#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;
ifstream f1;
ofstream f2;

#include "BST.h"

int main(int argc, char* argv[])
{
	string s, m, FW, TT, temp, All_D[10] = {"\0"};
	int start = 0, end = 0, i = 0, LengthFW = 0, char_count = 0, line = 0, OperationKey = 0, FirstWord = 1, confirm  = 0, confirm_arg = 0;
	int N_Arg = 0, flag_cut = 0, begin = 0;
	int flag_title = 0;
	//---------------------- Check the CMD inputs ---------------------//
	if(argc != 3)
	{
		cout << "Incorrect number of arguments" << endl;
		return 0;
	}
	//-----------------------------------------------------------------//
	f1.open(argv[1]);
	if(f1.fail())
	{
		cout << "File not found" << endl;
		return 0;
	}
	f1.close();
	//------------- Put the file into standard form to work with it ------------//
	/*fstream f3(argv[1], ios::in | ios::out | ios::app);
	if(f3.is_open())
		f3 << ' ';
	else
	{
		// Do nothing
	}
	f3.close();*/
	//--------------------------------------------------------------------//
	f1.open(argv[1]);
	f2.open(argv[2]);
	BST myTree;
	if(f1.fail())
	{
		cout << "File not found" << endl;
		return 0;
	}
	else
	{
		//---------------------- First Read The test file -------------------//
		while(f1.good())
		{
			line++;
			i = 0;
			LengthFW = 0;
			confirm = 0;
			start = 0;
			end = 0;
			N_Arg = 0;
			confirm_arg = 0;
			flag_title = 0;
			flag_cut = 0;
			begin = 0;
			FW = '\0';
			TT = '\0';
			for(int z = 0; z < 10; z++)
				All_D[z] = "\0";
			FirstWord = 1;
			getline(f1, s);
			//cout << s << endl;
			//cout << '\0' << '\r';
			//s = s + 'h';
			//cout << s << endl;
			//s.erase(s.length() - 1, 1);
			//s.erase(s.length(), 1);
			//cout << s << endl;
			//s.append("g");
			//s.push_back(' ');
			//s.append("g");
			//s.erase(s.length() - 1, 1);
			//s.append("    ");
			//cout << s << endl;
			//s = s + " \0";
			//cout << s << endl;
			//return 5;
			/*while((s[char_count+1] != '\0') && (s[char_count] !=  '\n')) 		// Plus 1 here
				char_count++;*/
			//---------------- Get the first word in the line ------------//
			while(FirstWord)
			{
				if(FirstWord)
				{
					while(s[LengthFW] != ' ' && s[LengthFW] != '\0' && s[LengthFW] != '\n' && s[LengthFW] != '\r')		// Plus 1 here
						LengthFW++;
					FW = s.substr(0, LengthFW);
					//cout << "First Word = " << FW << endl;
					//cout << "LengthFW = " << LengthFW << endl;
					FirstWord = 0;
				}
			}
			//--------------- If the first word is empty -----------------//
			if(LengthFW == 0)
				continue;
			//--------------- Check for the first word -------------------//
			if(FW == "ADD")
				OperationKey = 1;
			else if(FW == "Find")
				OperationKey = 2;
			else if(FW == "MOD")
				OperationKey = 3;
			else if(FW == "DEL")
				OperationKey = 4;
			else if(FW == "Print")
				OperationKey = 5;
			else
			{
				cout << "Invalid command" << endl;
				f2 << "Invalid command" << endl;
				OperationKey = 0;
			}
			//cout << "Operation Key = " << OperationKey << endl;
			//------------- Split the words after the first word -------------//
			//cout << "after first word = " << s[LengthFW+1] << endl;
			//i = LengthFW; // For skip the first word
			int start_1_3 = 0, end_1_3 = 0, flag_title = 1, flag_day = 1, flag_hour = 1, flag_extra = 1;
			int flag_error_title = 0, flag_error_day = 0, flag_error_hour = 0;
			string title = "\0", day = "\0", hour = "\0", extra = "\0";
			int day_int = 0, hour_int = 0;
			int RandomEnter = 0;
			if(OperationKey == 1 || OperationKey == 3) // ADD || MOD
			{
				for(int i = LengthFW; s[i] != '\0' && s[i] != '\r'; i++)
				{
					while(s[i] == ' ' || s[i] == '\t')
					{
						i++;
					}
					if(s[i] == '"' && flag_title == 1)
					{
						//cout << "Hello " << endl;
						start_1_3 = i;
						while(s[i] != '\0' && s[i] != '\r')
						{
							if(s[i] == '"')
							{
								end_1_3 = i;
							}
							i++;
						}
						//------------------//
						//cout << start_1_3 << endl;
						//cout << end_1_3 << endl;
						//cout << s[end_1_3 + 1] << endl;
						if(s[end_1_3 + 1] != ' ' && s[end_1_3 + 1] != '\t' && end_1_3 != start_1_3)
						{
							//cout << "I am here now" << endl;
							int RandomIterator = 0;
							RandomIterator = end_1_3;
							flag_error_title = 1;
							while(s[RandomIterator] != '\0' && s[RandomIterator] != '\r' && s[RandomIterator] != ' ')
							{
								if(s[RandomIterator] != ' ')
									end_1_3++;
								RandomIterator++;
							}
							end_1_3 = end_1_3 - 1;
						}
						//cout << "end_1_3 = " << end_1_3 << endl;
						//-----------------//
						if(end_1_3 == 0 || end_1_3 == start_1_3)
						{
							i = start_1_3;
							flag_error_title = 1;
							//cout << "In" << endl;
							while(s[i] != '\0' && s[i] != '\r')
							{
								if(s[i] == ' ' || s[i] == '\t')
								{
									end_1_3 = i;
									//flag_error_title = 1;
									break;
								}
								i++;
							}
							title = s.substr(start_1_3, end_1_3 - start_1_3);
							//cout << "title = " << title << endl;
							flag_title = 0;
							if(flag_error_title)
							{
								//cout << "Invalid title" << endl;
								//flag_error_title = 0;
							}
						}
						else if(end_1_3 != 0 && end_1_3 != start_1_3)
						{
							title = s.substr(start_1_3, end_1_3 - start_1_3 + 1);
							//cout << "title = " << title << endl;
							if(flag_error_title)
							{
								//cout << "Invalid title" << endl;
								//flag_error_title = 0;
							}
							flag_title = 0;
							i = start_1_3 + end_1_3 - start_1_3 + 1;
							// cout << "i = " << i << endl;
							// cout << "flag_day = " << flag_day << endl;
						}
					}
					else if(flag_title)
					{
						start_1_3 = i;
						flag_error_title = 1;
						while(s[i] != '\0')
						{
							if(s[i] == ' ' || s[i] == '\t')
							{
								end_1_3 = i;
								//flag_error_title = 1;
								break;
							}
							i++;
						}
						title = s.substr(start_1_3, end_1_3 - start_1_3);
						//cout << "title = " << title << endl;
						flag_title = 0;
						if(flag_error_title)
						{
							//cout << "Invalid title" << endl;
							//flag_error_title = 0;
						}
					}
					else if(flag_extra) // extras section
					{
						i = end_1_3 + 1;
						start_1_3 = end_1_3 + 1;
						//cout << "from extra = " << s[i] << endl;
						int j = 0, word  = 0;
						while(s[i] != '\0')
						{
							while(s[char_count] != '\0' && s[char_count] != '\r')
								char_count++;
							while((i < char_count) && s[i + j] != ' ' && s[i + j] != '\0' && s[i + j] != '\t' && s[i + j] != '\n' && s[i + j] != '\r') // Plus here
								j++;
							if((i < char_count) && j != 0)
							{
								m = s.substr(i, j);
								All_D[word] = m;
								word++;
							}
							i = i + j + 1;
							j = 0;
							char_count = 0;
						}
						i = 0;
						j = 0;
						/*while(All_D[i][j] != '\0')
						{
							cout << All_D[i] << endl;
							i++;
						}*/
						if(word == 2)
						{
							// check the title validity first
							if(flag_error_title)
							{
								cout << "Invalid title" << endl;
								f2 << "Invalid title" << endl;
								//flag_error_title = 0;
							}
							///////////////////////////////////////////
							// Day argument
							j = 0;
							while(All_D[0][j] != '\0' && All_D[0][j] != '\n')
							{
								if(All_D[0][j] >= '0' && All_D[0][j] <= '9')
								{
									// Do nothing thats right
								}
								else
								{
									flag_error_day  = 1;
									break;
								}
								j++;
							}
							if(flag_error_day == 0)
							{
								day_int = stoi(All_D[0]);
								//cout << "day_int = " << day_int << endl;
								if(day_int > 365 || day_int <= 0)
								{
									cout << "Invalid day" << endl;
									f2 << "Invalid day" << endl;
									flag_error_day  = 1;
								}
							}
							else
							{
								cout << "Invalid day" << endl;
								f2 << "Invalid day" << endl;
								//flag_error_day = 0;
							}

							// Hour argument
							j = 0;
							while(All_D[1][j] != '\0' && All_D[1][j] != '\n' && All_D[1][j] != '\r')
							{
								if(All_D[1][j] >= '0' && All_D[1][j] <= '9')
								{
									// Do nothing thats right
								}
								else
								{
									flag_error_hour  = 1;
									break;
								}
								j++;
							}
							if(flag_error_hour == 0)
							{
								hour_int = stoi(All_D[1]);
								//cout << "hour_int = " << hour_int << endl;
								if(hour_int > 23 || hour_int < 0)
								{
									cout << "Invalid hour" << endl;
									f2 << "Invalid hour" << endl;
									flag_error_hour = 1;
								}
							}
							else
							{
								cout << "Invalid hour" << endl;
								f2 << "Invalid hour" << endl;
								//flag_error_hour = 0;
							}

						}
						else
						{
							cout << "Invalid arguments" << endl;
							f2 << "Invalid arguments" << endl;
							flag_error_title = 1;
							flag_error_day = 1;
							flag_error_hour = 1;
						}

						//cout << "Flag_error_title = " << flag_error_title << endl;
						//cout << "Flag_error_day = " << flag_error_day << endl;
						//cout << "Flag_error_hour = " << flag_error_hour << endl;
						if(flag_error_title == 0 && flag_error_day == 0 && flag_error_hour == 0)
						{
							// Finally correct data, ready to add it to the tree
							if(OperationKey == 1)
							{
								myTree.AddLeaf(day_int, hour_int, title);
								//myTree.PrintInOrder();
							}
							else if(OperationKey == 3)
							{
								//cout << "Title Here = " << title << endl;
								myTree.MOD(day_int, hour_int, title);
								//myTree.PrintInOrder();
							}
						}
						flag_error_title = 0;
						flag_error_day = 0;
						flag_error_hour = 0;
						flag_extra = 0;
					}
				}
			}
			else if(OperationKey == 2 || OperationKey == 4)	// Find || DEL
			{
				i = LengthFW;
				start_1_3 = LengthFW;
				end_1_3 = LengthFW;
				char_count = LengthFW;
				/*if(s[i] == '\0' || s[i] == '\n' || s[i] == ' ')
					cout << "Yes a new line char" << endl;*/
				//cout << "from extra = " << s[i] << endl;
				int j = 0, word  = 0;
				while(s[i] != '\0' && s[i] != '\n' && s[i] != '\r')
				{
					while(s[char_count] != '\0' && s[char_count] != '\r')
						char_count++;
					while((i < char_count) && s[i + j] != ' ' && s[i + j] != '\0' && s[i + j] != '\t' && s[i + j] != '\n' && s[i + j] != '\r') // Plus here
						j++;
					if((i < char_count) && j != 0)
					{
						m = s.substr(i, j);
						All_D[word] = m;
						word++;
					}
					i = i + j + 1;
					j = 0;
					char_count = 0;
				}
				i = 0;
				j = 0;
				/*while(All_D[i][j] != '\0')
				{
					cout << All_D[i] << endl;
					i++;
				}*/
				//cout << "CharCount = " << char_count << endl;
				if(char_count - LengthFW == 0 || word != 2)
				{
					cout << "Invalid arguments" << endl;
					f2 << "Invalid arguments" << endl;
				}
				else
				{
					// Get the data
					// Day argument
					j = 0;
					while(All_D[0][j] != '\0' && All_D[0][j] != '\n' && All_D[0][j] != '\r')
					{
						if(All_D[0][j] >= '0' && All_D[0][j] <= '9')
						{
							// Do nothing thats right
						}
						else
						{
							flag_error_day  = 1;
							break;
						}
						j++;
					}
					if(flag_error_day == 0)
					{
						day_int = stoi(All_D[0]);
						//cout << "day_int = " << day_int << endl;
						if(day_int > 365 || day_int <= 0)
						{
							cout << "Invalid day" << endl;
							f2 << "Invalid day" << endl;
							flag_error_day  = 1;
						}
					}
					else
					{
						cout << "Invalid day" << endl;
						f2 << "Invalid day" << endl;
						//flag_error_day = 0;
					}

					// Hour argument
					j = 0;
					while(All_D[1][j] != '\0' && All_D[1][j] != '\n' && All_D[1][j] != '\r')
					{
						if(All_D[1][j] >= '0' && All_D[1][j] <= '9')
						{
							// Do nothing thats right
						}
						else
						{
							flag_error_hour  = 1;
							break;
						}
						j++;
					}
					if(flag_error_hour == 0)
					{
						hour_int = stoi(All_D[1]);
						//cout << "hour_int = " << hour_int << endl;
						if(hour_int > 23 || hour_int < 0)
						{
							cout << "Invalid hour" << endl;
							f2 << "Invalid hour" << endl;
							flag_error_hour = 1;
						}
					}
					else
					{
						cout << "Invalid hour" << endl;
						f2 << "Invalid hour" << endl;
						//flag_error_hour = 0;
					}
					//cout << "Flag_error_day = " << flag_error_day << endl;
					//cout << "Flag_error_hour = " << flag_error_hour << endl;
					if(flag_error_day == 0 && flag_error_hour == 0)
					{
						// Finally correct data, ready to add it to the tree
						if(OperationKey == 2)
						{
							myTree.ReturnNode(day_int, hour_int);

						}
						else if(OperationKey == 4)
						{
							myTree.RemoveNode(day_int * 100 + hour_int);
						}
					}
					flag_error_day = 0;
					flag_error_hour = 0;
					flag_extra = 0;
				}

			}
			else if(OperationKey == 5) // Print
			{
				i = LengthFW;
				start_1_3 = LengthFW;
				end_1_3 = LengthFW;
				char_count = LengthFW;
				/*if(s[i] == '\0' || s[i] == '\n' || s[i] == ' ')
						cout << "Yes a new line char" << endl;*/
				//cout << "from extra = " << s[i] << endl;
				int j = 0, word  = 0;
				int entered_at_least_one_time = 0;
				//cout << "I am here in the print function" << endl;
				while(s[i] != '\0' && s[i] != '\n' && s[i] != '\r')
				{
					while(s[char_count] != '\0' && s[char_count] != '\r')
						char_count++;
					//cout << "char_cout = " << char_count << endl;
					while((i < char_count) && s[i + j] != ' ' && s[i + j] != '\0' && s[i + j] != '\t' && s[i + j] != '\n' && s[i + j] != '\r') // Plus here
						j++;
					if((i < char_count) && j != 0)
					{
						m = s.substr(i, j);
						All_D[word] = m;
						word++;
					}
					i = i + j + 1;
					j = 0;
					char_count = 0;
					entered_at_least_one_time = 1;
				}
				i = 0;
				j = 0;
				/*while(All_D[i][j] != '\0')
				{
					cout << All_D[i] << endl;
					i++;
				}*/
				//cout << "CharCount = " << char_count << endl;
				if(entered_at_least_one_time == 0)
				{
					myTree.PrintInOrder();
				}
				else
				{
					if(char_count != 0 || All_D[0][0] != '\0')
					{
						cout << "Invalid arguments" << endl;
						f2 << "Invalid arguments" << endl;
					}
					else
					{
						myTree.PrintInOrder();
					}
				}
				
				
				/*if(char_count != 0 || All_D[0][0] != '\0' || All_D[0][0] != '\r')
				{
					cout << "Invalid arguments" << endl;
					f2 << "Invalid arguments" << endl;
				}
				else
				{
					myTree.PrintInOrder();
				}*/
			}
		}
	}
	f1.close();
	return 0;
}
