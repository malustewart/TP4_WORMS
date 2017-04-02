
// .hpp para COMO HACER QUE DOS CLASES SE USEN MUTUAMENTE :)


////////// para la clase Graphic:
 
class Worm; // se declara la clase Worm para que Graphic la pueda usar.

class Graphic
{
public:
	Graphic () //constructor (SOLO INICIALIZA EL OBJETO)
	{
	}

	bool setWorm(Worm& w_1) //Configura el objeto
	{
		w1 = & w_1;
		return true;
	}

	bool setWorm(Worm& w_2) //Configura el objeto
	{
		w2 = &w_2;
		return true;
	}

private:
	Worm * w1;
	Worm * w2;
};

////////// para la clase Worm:
class Graphic; // se declara la clase Worm para que Graphic la pueda usar.

class Worm
{
public:
	Worm() //constructor (SOLO INICIALIZA EL OBJETO)
	{
	}

	bool setGraphic(Graphic& g_1) //Configura el objeto
	{
		g1 = &g_1;
		return true;
	}

	bool setGraphic(Graphi & g_2) //Configura el objeto
	{
		g2 = &g_2;
		return true;
	}

private:
	Graphic * g1;
	Graphic * g2;
};