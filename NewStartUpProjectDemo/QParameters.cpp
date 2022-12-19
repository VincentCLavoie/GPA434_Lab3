#include "QParameters.h"


#include <QSpinBox>
#include <QFormLayout>
#include <QtMath>


QParameters::QParameters(size_t maxItems, QWidget * parent)
	:	QWidget(parent),
		mNbrOfBushes{ new QSpinBox },
		mNbrOfRabbits{ new QSpinBox },
		mNbrOfFoxes{ new QSpinBox }
{
	const size_t minMaxNbr{ 10 };

	mNbrOfBushes->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfBushes->setValue(minMaxNbr);

	mNbrOfRabbits->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfRabbits->setValue(minMaxNbr);

	mNbrOfFoxes->setRange(1, qMax(static_cast<size_t>(minMaxNbr), maxItems));
	mNbrOfFoxes->setValue(minMaxNbr);

	QFormLayout * layout{ new QFormLayout };
	layout->addRow("Nombre de buissons ", mNbrOfBushes);
	layout->addRow("Nombre de lapins ", mNbrOfRabbits);
	layout->addRow("Nombre de renards ", mNbrOfFoxes);
	
	setLayout(layout);
}

size_t QParameters::nbrOfBushes() const
{
	return static_cast<size_t>(mNbrOfBushes->value());
}

size_t QParameters::nbrOfRabbits() const
{
	return static_cast<size_t>(mNbrOfRabbits->value());
}

size_t QParameters::nbrOfFoxes() const
{
	return static_cast<size_t>(mNbrOfRabbits->value());
}