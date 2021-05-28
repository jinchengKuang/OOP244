/* Citation and Sources...
Final Project Milestone 5
Module:   PreTriage
Filename: PreTriage.cpp
Version   1.0
Author	  Jincheng Kuang
Revision History
-----------------------------------------------------------
Date       Reason
2020/4/7  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		if (m_dataFilename != nullptr)
		{
			delete[] m_dataFilename;
		}
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}

	PreTriage::~PreTriage()
	{
		if (m_dataFilename != nullptr)
		{
			ofstream fout(m_dataFilename);
			ifstream fin(m_dataFilename);
			if (fout.is_open())
			{
				cout << "Saving Average Wait Times,\n   COVID Test: " << m_averCovidWait << "\n   Triage: " << m_averTriageWait << endl << "Saving m_lineup..." << endl;
				fout << m_averCovidWait << "," << m_averTriageWait << endl;

				for (int i = 0; i < m_lineupSize; i++)
				{
					m_lineup[i]->fileIO(true);
					m_lineup[i]->write(fout);
					fout << endl;

					cout << i + 1 << "- ";
					m_lineup[i]->write(cout);
					cout << endl;
				}

				fout.close();
			}

			for (int i = 0; i < m_lineupSize; i++)
			{
				delete m_lineup[i];
				m_lineup[i] = nullptr;
			}
			delete[] m_dataFilename;
			m_dataFilename = nullptr;
			cout << "done!" << endl;
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p)const
	{
		unsigned int count = 0;
		for (int i = 0; i < maxNoOfPatients && m_lineup[i] != nullptr; i++)
		{
			if (*m_lineup[i] == p)
			{
				count++;
			}
		}
		count--;
		return p == 'C' ? Time(m_averCovidWait) *= count : Time(m_averTriageWait) *= count;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time CT;
		CT.setToNow();
		unsigned int PTN = p.number();

		if (p == 'C')
		{
			m_averCovidWait = ((CT - Time(p)) + (m_averCovidWait *= (PTN - 1))) / PTN;
		}
		else if (p == 'T')
		{
			m_averTriageWait = ((CT - Time(p)) + (m_averTriageWait *= (PTN - 1))) / PTN;
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int index = -1;
		bool found = false;
		for (int i = 0; i < maxNoOfPatients && !found; i++)
		{
			if (m_lineup[i]->type() == type)
			{
				found = true;
				index = i;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		if (m_dataFilename != nullptr)
		{
			ifstream fin(m_dataFilename);
			if (fin.is_open())
			{
				cout << "Loading data..." << endl;

				m_averCovidWait.read(fin);
				fin.ignore();
				m_averTriageWait.read(fin);
				fin.ignore();

				for (int i = 0; i < maxNoOfPatients; i++)
				{
					m_lineup[m_lineupSize] = nullptr;
					char ch = fin.get();
					if (ch == 'C')
					{
						m_lineup[m_lineupSize] = new CovidPatient;
					}
					else if (ch == 'T')
					{
						m_lineup[m_lineupSize] = new TriagePatient;
					}
					fin.get();
					if (m_lineup[m_lineupSize] != nullptr)
					{
						m_lineup[m_lineupSize]->fileIO(true);
						m_lineup[m_lineupSize]->csvRead(fin);
						m_lineup[m_lineupSize]->fileIO(false);
						m_lineupSize++;
					}
				}
				if (m_lineupSize > 0 && fin.eof())
				{
					cout << m_lineupSize << " Records imported..." << endl << endl;
				}
				else if (m_lineupSize <= 0 && fin.eof())
				{
					cout << "No data or bad data file!" << endl << endl;
				}
				else if (!fin.eof())
				{
					cout << "Warning: number of records exceeded 100" << endl;
					cout << m_lineupSize << " Records imported..." << endl << endl;
				}
				fin.close();
			}
			else
			{
				cout << "File cannot open" << endl;
			}
		}
	}

	void PreTriage::reg()
	{
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			int selection = -1;
			m_pMenu >> selection;
			if (selection != 0)
			{
				if (selection == 1)
				{
					m_lineup[m_lineupSize] = new CovidPatient;
				}
				else if (selection == 2)
				{
					m_lineup[m_lineupSize] = new TriagePatient;
				}
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				m_lineup[m_lineupSize]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[m_lineupSize]->write(cout);
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
			}
			m_lineupSize++;
		}
	}

	void PreTriage::admit()
	{
		int selection = -1;
		char type = '\0';
		int index = -1;
		m_pMenu >> selection;
		if (selection != 0)
		{
			if (selection == 1)
			{
				type = 'C';
			}
			else if (selection == 2)
			{
				type = 'T';
			}
			index = indexOfFirstInLine(type);
			if (index >= 0)
			{
				cout << endl << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for ";
				m_lineup[index]->write(cout);
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}

	void PreTriage::run(void)
	{
		int selection = -1;
		do
		{
			//cout << endl;
			m_appMenu >> selection;
			if (selection == 1)
			{
				reg();
			}
			else if (selection == 2)
			{
				admit();
			}
		} while (selection != 0);
	}
}