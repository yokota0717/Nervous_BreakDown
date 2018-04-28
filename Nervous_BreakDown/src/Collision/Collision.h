#pragma once
#include "../Figure/Vec.h"
#include "../Figure/Shape.h"


namespace Math{
	//�����蔻����s���N���X
	class Collider {
	public:
		Collider() {};
		~Collider() {};

		//����segment�ƒ���line�̋�ʂ��邩��...

		//�����蔻��֐�
		virtual bool Collision(Vec) = 0;				//�_
		virtual bool Collision(Vec,Vec) = 0;			//����
		virtual bool Collision(Box2D) = 0;				//��`
		virtual bool Collision(Circle) = 0;				//�~


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