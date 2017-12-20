#include <iostream>
using namespace std;

class BaseDraw
{
public:
	virtual void Draw()
	{
		cout << " /\\ " << endl;
	}
};
class OneDraw : public BaseDraw
{
    void Draw()
	{
		BaseDraw::Draw();
		cout << "//\\\\" << endl;
	}
};
class TwoDraw : public BaseDraw
{
    void Draw()
	{
		BaseDraw::Draw();
		cout << "/**\\" << endl;
	}
};
class ThreeDraw : public BaseDraw
{
    void Draw()
	{
		BaseDraw::Draw();
		cout << "/++\\" << endl;
	}
};
int main() {
	BaseDraw* draw[3];

	draw[0] = new OneDraw();
	draw[2] = new TwoDraw();
	draw[1] = new ThreeDraw();

	for (int i = 0; i < 3; i++)
	{
		cout << "Drawing " << i + 1 << ":" << endl;
		draw[i]->Draw();
	}
	return 0;
}
