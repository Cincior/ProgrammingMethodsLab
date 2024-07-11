#include "libExceptions.h"

void showException(EXCEPTION_CODE error)
{
	switch (error)
	{
	case EXCEPTION_CODE::openError:
		cerr << "Blad otwarcia pliku\n";
		break;
	case EXCEPTION_CODE::readError:
		cerr << "Blad wczytania danych\n";
		break;
	case EXCEPTION_CODE::lackOfMemoryError:
		cerr << "Blad braku pamieci!\n";
		break;
	case EXCEPTION_CODE::outOfRangeError:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cerr << "Blad wyjscia poza mozliwy zakres!\n";
		break;
	case EXCEPTION_CODE::numberError:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cerr << "Niepoprawna liczba!\n";
		break;
	default:
		cerr << "Wystapil nieznany blad\n";
		break;
	}
}
