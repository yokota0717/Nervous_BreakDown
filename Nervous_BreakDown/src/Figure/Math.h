#pragma once
#include <cmath>


namespace Math {
	//円周率
	static float PI = 3.141592653589793238462643383279502884197f;
	//角度変換
	inline float ToDegree(float radian);
	inline float ToRadian(float degree) {
		return (degree / 180.0f)*PI;
	}
	//重力
	inline float Gravity(int onemeter) {
		return ((9.8f / 60) / 60)*onemeter;
	}


	//ベクトルクラス
	//デフォルト引数でz=0.0fなので2次元でも使えるね！
	class Vec {
	public:
		float x, y, z;		//座標

		Vec(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
			x(x),
			y(y),
			z(z)
		{}
		~Vec() {};


		//ベクトルを正規化
		Vec Normalize() {
			float len = GetVecLen(*this);
			if (len == 0) return *this;
			return Vec(x /= len, y /= len);
		}
		//ベクトルを度数法で回転する
		Vec RotateVecDegree(Vec v, float deg) {
			float rad = (deg / 180) * Math::PI;
			float tempX = v.x;
			float tempY = v.y;
			v.x = float(tempX*cos(rad) - tempY*sin(rad));
			v.y = float(tempX*sin(rad) + tempY*cos(rad));
			return v;
		}		
		//ベクトルを弧度法で回転する
		Vec RotateVecRadian(Vec v, float rad) {
			float tempX = v.x;
			float tempY = v.y;
			v.x = float(tempX*cos(rad) - tempY*sin(rad));
			v.y = float(tempX*sin(rad) + tempY*cos(rad));
			return v;
		}
		//2つのベクトルの内積を返す
		static float GetDotVec(Vec v1, Vec v2) {
			return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
		}
		//2つのベクトルの外積を返す(2次元)
		static float GetCrossVec2(Vec v1, Vec v2) {
			return (v1.x*v2.y) - (v1.y*v2.x);
		}
		//2つのベクトルの外積を返す(3次元)
		Vec GetCrossVec3(Vec v1, Vec v2) {
			Vec Result;
			Result.x = v1.y*v2.z - v1.z*v2.y;
			Result.y = v1.z*v2.x - v1.x*v2.z;
			Result.z = v1.x*v2.y - v1.y*v2.x;
			return Result;
		}
		//ベクトルの長さを得る
		float GetVecLen(Vec v) {
			return std::pow(v.x*v.x + v.y*v.y + v.z*v.z, 0.5f);
		}
		//正規化されたベクトルを得る
		Vec GetUnitVec(Vec v) {
			float len = GetVecLen(v);
			Vec Result = v;
			Result.x /= len;
			Result.y /= len;
			Result.z /= len;
			return Result;
		}
		//ベクトルをn倍する
		Vec VecScale(Vec v, float n) {
			Vec Result;
			Result.x *= n;
			Result.y *= n;
			Result.z *= n;
			return Result;
		}
		//2次元ベクトルの単位法線ベクトルを得る v1×v2 ベクトルの左側の方 (注:数学の座標系)
		Vec GetUnitNormVec2Left(Vec v) {	//左回りに90度回転してるだけやで☆
			Vec Result = v;
			float tmpx = Result.x;
			Result.x = Result.y;
			Result.y = (-1)*tmpx;
			Result = GetUnitVec(Result);
			return Result;
		}
		//2次元ベクトルの単位法線ベクトルを得る v1×v2 ベクトルの右側の方 (注:数学の座標系)
		Vec GetUnitNormVec2Right(Vec v) {	//こっちは右回りやで☆
			Vec Result = v;
			float tmpx = Result.x;
			Result.x = (-1)*Result.y;
			Result.y = tmpx;
			Result = GetUnitVec(Result);
			return Result;
		}
		//3次元平面の単位法線ベクトルを得る(注:数学の座標系) v1,v2は平面上に存在するベクトル
		Vec GetUnitNormVec3(Vec v1, Vec v2) {
			Vec Result = GetCrossVec3(v1, v2);
			Result = GetUnitVec(Result);
			return Result;
		}



		//オペレータ定義
		Vec& operator = (const Vec& v) { x = v.x; y = v.y; z = v.z; return *this; }
		const Vec operator + (const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
		const Vec operator - (const Vec& v) const { return Vec(x - v.x, y - v.y, z - v.z); }
		const Vec operator * (const float n) const { return Vec(x*n, y*n, z*n); }
		const Vec operator / (const float n) const { return Vec(x / n, y / n, z / n); }
		Vec& operator += (const Vec& v) { x += v.x; y += v.y; z += v.z; return *this; }
		Vec& operator -= (const Vec& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		Vec& operator *= (const float n) { x *= n; y *= n; z *= n; return *this; }
		Vec& operator /= (const float n) { x /= n; y /= n; z /= n; return *this; }

	};




	struct Box2D {				//四角形構造体
		float	x, y, w, h;		//左上の座標、幅、高さ

		Box2D() :x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
		Box2D(float x, float y, float w, float h) :x(x), y(y), w(w), h(h) {}
		~Box2D() {}
		void Offset(Vec v) {							//引数がベクトル
			x += v.x;
			y += v.y;
		}
		void Offset(float vx, float vy) {			//引数がx,y
			x += vx;
			y += vy;
		}
		Box2D OffsetCopy(float vx, float vy) const {	//x,yを引数にしてBox2Dを返す
			return Box2D(x + vx, y + vy, w, h);
		}
		Box2D OffsetCopy(const Vec& v)const {
			return Box2D(x + v.x, y + v.y, w, h);
		}
		bool Hit(const Box2D& b) const {		//矩形同士の当たり判定
			if (x < b.x + b.w	&&
				b.x < x + w &&
				y < b.y + b.h	&&
				b.h < y + h) {
				return true;
			}
			return false;
		}
		bool Hit(const Vec& b) const {		//矩形とベクトルの当たり判定
			if (x < b.x	&&
				b.x < x + w &&
				y < b.y	&&
				b.y < y + h) {
				return true;
			}
			return false;
		}
	};

	struct Circle {
		float x, y, z;		//中心座標
		float r;			//半径

		Circle() :x(0.0f), y(0.0f), z(0.0f), r(0.0f) {};
		Circle(float x, float y, float z, float r) :x(x), y(y), z(z), r(r) {};
		~Circle() {};

		void Offset(Vec v) {							//引数がベクトル
			x += v.x;
			y += v.y;
			z += v.z;
		}
		void Offset(float vx, float vy, float vz = 0.0f) {			//引数がx,y,z
			x += vx;
			y += vy;
			z = vz;
		}
		Circle OffsetCopy(float vx, float vy, float vz = 0.0f) const {	//x,yを引数にしてCircleを返す
			return Circle(x + vx, y + vy, z + vz, r);
		}
		Circle OffsetCopy(const Vec& v)const {
			return Circle(x + v.x, y + v.y, z + v.z, r);
		}
		bool Hit(const Circle& c) const {
			//中心間の距離が二つの半径の和より小さかったらtrue
			float mx = powf(x - c.x, 2.0f);
			float my = powf(y - c.y, 2.0f);
			float mz = powf(z - c.z, 2.0f);
			if (powf(mx + my + mz, 0.5f) <= (r + c.r)) return true;
			return false;
		}
		bool Hit(const Vec& v) const {
			float mx = powf(x - v.x, 2.0f);
			float my = powf(y - v.y, 2.0f);
			float mz = powf(z - v.z, 2.0f);
			if (powf(mx + my + mz, 0.5f) <= r) return true;
			return false;
		}

	};

	struct Triangle {
		Vec v1, v2, v3;		//3頂点

		Triangle(Vec v1, Vec v2, Vec v3) :
			v1(v1), v2(v2), v3(v3)
		{}

	};

	struct Orval {
		float x, y;		//中心座標
		float lr, sr;	//長軸、短軸	 long radius,shot radius
		float angle;	//長軸のx軸からの傾き

		Orval(float x, float y, float lr, float sr, float ang) :
			x(x), y(y),
			lr(lr), sr(sr),
			angle(ang)
		{}
	};

}