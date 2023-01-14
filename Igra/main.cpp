#include "settings.h"
#include "functions.h"
#include "ball.h"
#include "bat.h"
using namespace sf;


int main()
{
	srand(time(nullptr));
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//�����
	Ball ball;
	ballInit(ball);

	Bat bat;
	BatInit(bat);


	//������ ��� ������
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	initText(leftPlayerScoreText, leftPlayerScore, font, charSize, leftTextStartPos);
	Text rightPlayerScoreText;
	initText(rightPlayerScoreText, rightPlayerScore, font, charSize, rightTextStartPos);

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//2 ���������� ��������

		ballUpdate(ball);

		batUpdate(bat);
		//�������� ������� ������
		//���� ������� W ������ - ���� ������� ����
		
		//������� �������		
		leftBat.move(0, leftBatSpeedY);
		//� ����� �������� ��������
		leftBatSpeedY = 0;
		//������ �������
		
		//������� �������		
		rightBat.move(0, rightBatSpeedY);
		//� ����� �������� ��������
		rightBatSpeedY = 0;

		//��������� ���� �� �������
		//��������� �����-�������� ������ ���������� ������ ���� ��������
		float ballX = ball.getPosition().x;
		float ballY = ball.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS, ballY };
		Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
		//�������� �� ����� �������
		if (pointInRect(leftBat, midLeft)) ball_speedx = -ball_speedx;
		if (pointInRect(leftBat, midBottom) || pointInRect(leftBat, midTop))
			ball_speedy = -ball_speedy;
		//�������� �� ������ �������
		if (pointInRect(rightBat, midRight)) ball_speedx = -ball_speedx;
		if (pointInRect(rightBat, midBottom) ||
			pointInRect(rightBat, midTop))
			ball_speedy = -ball_speedy;

		//3 ��������� ����
		//3.1 ������� ����
		window.clear();
		//3.2 ��������� �������� (� ������!)
		window.draw(leftBat);
		window.draw(rightBat);
		batDraw(window,bat);
			window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);
		//3.3 ����� �� �����
		window.display();
	}
	return 0;
}