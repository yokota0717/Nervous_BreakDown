#pragma once
#include "../Figure/Vec.h"
#include "../Figure/Shape.h"


namespace Math{
	//当たり判定を行うクラス
	class Collider {
	public:
		Collider() {};
		~Collider() {};

		//線分segmentと直線lineの区別いるかな...

		//あたり判定関数
		virtual bool Collision(Vec) = 0;				//点
		virtual bool Collision(Vec,Vec) = 0;			//線分
		virtual bool Collision(Box2D) = 0;				//矩形
		virtual bool Collision(Circle) = 0;				//円


	};

	class Box2DCollider :public Collider {
	public:
		Box2D col;

		Box2DCollider(float x, float y, float w, float h);
		bool Collision(Vec) override;
		bool Collision(Vec, Vec) override;
		bool Collision(Box2D) override;
		bool Collision(Circle) override;

	};

	class CircleCollider :public Collider {
	public:
		Circle col;

		CircleCollider(float x, float y, float r);
		bool Collision(Vec) override;
		bool Collision(Vec, Vec) override;
		bool Collision(Box2D) override;
		bool Collision(Circle) override;

	};

	class TriangleCollider :public Collider {
	public:
		Triangle col;

		TriangleCollider(Vec, Vec, Vec);
		bool Collision(Vec) override;
		bool Collision(Vec, Vec) override;
		bool Collision(Box2D) override;
		bool Collision(Circle) override;

	};

	class OrvalCollider :public Collider {
	public:
		Orval col;

		OrvalCollider(float x, float y, float lr, float sr, float ang);
		bool Collision(Vec) override;
		bool Collision(Vec, Vec) override;
		bool Collision(Box2D) override;
		bool Collision(Circle) override;
	};
}