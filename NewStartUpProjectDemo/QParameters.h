#ifndef Q_PARAMETERS_H
#define Q_PARAMETERS_H


#include <QWidget>

class QSpinBox;


class QParameters : public QWidget
{
	Q_OBJECT

public:
	QParameters(size_t maxItems = 250, QWidget * parent = nullptr);

	size_t nbrOfBushes() const;
	size_t nbrOfRabbits() const;
	size_t nbrOfFoxes() const;

protected:
	QSpinBox * mNbrOfBushes;
	QSpinBox * mNbrOfRabbits;
	QSpinBox* mNbrOfFoxes;
};


#endif // Q_PARAMETERS_H