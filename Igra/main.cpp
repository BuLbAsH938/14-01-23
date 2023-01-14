#include "settings.h"
#include "functions.h"
#include "ball.h"
#include "bat.h"
using namespace sf;


int main()
{
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//шарик
	Ball ball;
	ballInit(ball);

	Bat bat;
	BatInit(bat);


	//тексты для счетов
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов

		ballUpdate(ball);

		batUpdate(bat);
		//Проверка нажатий клавиш
		//если клавиша W нажата - лева ракетка вниз
		
		//двигаем ракетку		
		leftBat.move(0, leftBatSpeedY);
		//и сразу обнуляем скорость
		leftBatSpeedY = 0;
		//правая ракетка
		
		//двигаем ракетку		
		rightBat.move(0, rightBatSpeedY);
		//и сразу обнуляем скорость
		rightBatSpeedY = 0;

		//Отбивание мяча от ракетки
		//вычисляем точки-середины сторон описанного вокруг мяча квадрата
		float ballX = ball.getPosition().x;
		float ballY = ball.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS, ballY };
		Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
		//ударился об левую ракетку
		if (pointInRect(leftBat, midLeft)) ball_speedx = -ball_speedx;
		if (pointInRect(leftBat, midBottom) || pointInRect(leftBat, midTop))
			ball_speedy = -ball_speedy;
		//ударился об правую ракетку
		if (pointInRect(rightBat, midRight)) ball_speedx = -ball_speedx;
		if (pointInRect(rightBat, midBottom) ||
			pointInRect(rightBat, midTop))
			ball_speedy = -ball_speedy;

		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftBat);
		window.draw(rightBat);
		batDraw(window,bat);
			window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 вывод на экран
		window.display();
	}
	return 0;
}