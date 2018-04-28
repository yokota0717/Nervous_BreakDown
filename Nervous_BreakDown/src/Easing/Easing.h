//#pragma once
//
//#include "../define.h"
//#include <math.h>
//#include <string>
//
//enum class EasingName
//{
//	LINEAR,
//	BACK_IN,
//	BACK_OUT,
//	BACK_INOUT,
//	BOUNCE_OUT,
//	BOUNCE_IN,
//	BOUNCE_INOUT,
//	CIRCLE_IN,
//	CIRCLE_OUT,
//	CIRCLE_INOUT,
//	CUBIC_IN,
//	CUBIC_OUT,
//	CUBIC_INOUT,
//	ELASTIC_IN,
//	ELASTIC_OUT,
//	ELASTIC_INOUT,
//	EXPO_IN,
//	EXPO_OUT,
//	EXPO_INOUT,
//	QUAD_IN,
//	QUAD_OUT,
//	QUAD_INOUT,
//	QUART_IN,
//	QUART_OUT,
//	QUART_INOUT,
//	QUINT_IN,
//	QUINT_OUT,
//	QUINT_INOUT,
//	SINE_IN,
//	SINE_OUT,
//	SINE_INOUT
//};
//
//inline std::string GetName(const EasingName& n)
//{
//	std::string name[]
//	{
//		"LINEAR",
//		"BACK_IN",
//		"BACK_OUT",
//		"BACK_INOUT",
//		"BOUNCE_OUT",
//		"BOUNCE_IN",
//		"BOUNCE_INOUT",
//		"CIRCLE_IN",
//		"CIRCLE_OUT",
//		"CIRCLE_INOUT",
//		"CUBIC_IN",
//		"CUBIC_OUT",
//		"CUBIC_INOUT",
//		"ELASTIC_IN",
//		"ELASTIC_OUT",
//		"ELASTIC_INOUT",
//		"EXPO_IN",
//		"EXPO_OUT",
//		"EXPO_INOUT",
//		"QUAD_IN",
//		"QUAD_OUT",
//		"QUAD_INOUT",
//		"QUART_IN",
//		"QUART_OUT",
//		"QUART_INOUT",
//		"QUINT_IN",
//		"QUINT_OUT",
//		"QUINT_INOUT",
//		"SINE_IN",
//		"SINE_OUT",
//		"SINE_INOUT",
//	};
//	return name[static_cast<int>(n)];
//}
//
//template<typename T>
//class Easing {
//public:
//	Easing() :
//		start(T()),
//		end(T()),
//		duration(0),
//		elapse(0)
//	{}
//	Easing(T s, T e, int dur, int elp) :
//		start(s),
//		end(e),
//		duration(dur),
//		elapse(elp)
//	{}
//
//private:
//	T start;			//開始(座標だったりサイズだったり)
//	T end;				//終了
//	int duration;		//何秒で終わらせるか
//	int elapse;			//経過時間
//};
//
////引用URL：https://qiita.com/hart_edsf/items/962ac03281b871dcc0df
////イージング関数
//namespace Ease
//{
//	float InQuad(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return max * t*t + min;
//	}
//	float OutQuad(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return -max * t*(t - 2) + min;
//	}
//	float InOutQuad(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		if (t / 2 < 1)
//			return max / 2 * t * t + min;
//		--t;
//		return -max * (t * (t - 2) - 1) + min;
//	}
//	float InCubic(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return max * t*t*t + min;
//	}
//	float OutCubic(float t, float totaltime, float max, float min) {
//		max -= min;
//		t = t / totaltime - 1;
//		return max * (t*t*t + 1) + min;
//	}
//	float InOutCubic(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		if (t / 2 < 1)
//			return max / 2 * t*t*t + min;
//		t -= 2;
//		return max / 2 * (t*t*t + 2) + min;
//	}
//	float InQuart(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return max * t*t*t*t + min;
//	}
//	float OutQuart(float t, float totaltime, float max, float min) {
//		max -= min;
//		t = t / totaltime - 1;
//		return -max * (t*t*t*t - 1) + min;
//	}
//	float InOutQuart(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		if (t / 2 < 1)
//			return max / 2 * t*t*t*t + min;
//		t -= 2;
//		return -max / 2 * (t*t*t*t - 2) + min;
//	}
//	float InQuint(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return max * t*t*t*t*t + min;
//	}
//	float OutQuint(float t, float totaltime, float max, float min) {
//		max -= min;
//		t = t / totaltime - 1;
//		return max * (t*t*t*t*t + 1) + min;
//	}
//	float InOutQuint(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		if (t / 2 < 1)
//			return max / 2 * t*t*t*t*t + min;
//		t -= 2;
//		return max / 2 * (t*t*t*t*t + 2) + min;
//	}
//	float InSine(float t, float totaltime, float max, float min) {
//		max -= min;
//		return -max * cos(t*Math::ToRadian(90) / totaltime) + max + min;
//	}
//	float OutSine(float t, float totaltime, float max, float min) {
//		max -= min;
//		return max * sin(t*Math::ToRadian(90) / totaltime) + min;
//	}
//	float InOutSine(float t, float totaltime, float max, float min) {
//		max -= min;
//		return -max / 2 * (cos(t*Math::PI / totaltime) - 1) + min;
//	}
//	float InExp(float t, float totaltime, float max, float min) {
//		max -= min;
//		return t == 0.0 ? min : max * powf(2, 10 * (t / totaltime - 1)) + min;
//	}
//	float OutExp(float t, float totaltime, float max, float min) {
//		max -= min;
//		return t == totaltime ? max + min : max * (-powf(2, -10 * t / totaltime) + 1) + min;
//	}
//	float InOutExp(float t, float totaltime, float max, float min) {
//		if (t == 0.0)
//			return min;
//		if (t == totaltime)
//			return max;
//		max -= min;
//		t /= totaltime;
//
//		if (t / 2 < 1)
//			return max / 2 * powf(2, 10 * (t - 1)) + min;
//		--t;
//		return max / 2 * (-powf(2, -10 * t) + 2) + min;
//
//	}
//	float InCirc(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		return -max * (sqrt(1 - t * t) - 1) + min;
//	}
//	float OutCirc(float t, float totaltime, float max, float min) {
//		max -= min;
//		t = t / totaltime - 1;
//		return max * sqrt(1 - t * t) + min;
//	}
//	float InOutCirc(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//		if (t / 2 < 1)
//			return -max / 2 * (sqrt(1 - t * t) - 1) + min;
//		t -= 2;
//		return max / 2 * (sqrt(1 - t * t) + 1) + min;
//	}
//	float InBack(float t, float totaltime, float max, float min, float s) {
//		max -= min;
//		t /= totaltime;
//		return max * t*t*((s + 1)*t - s) + min;
//	}
//	float OutBack(float t, float totaltime, float max, float min, float s) {
//		max -= min;
//		t = t / totaltime - 1;
//		return max * (t*t*((s + 1)*t*s) + 1) + min;
//	}
//	float InOutBack(float t, float totaltime, float max, float min, float s) {
//		max -= min;
//		s *= 1.525f;
//		if (t / 2 < 1)
//			return max * (t*t*((s + 1)*t - s)) + min;
//
//		t -= 2;
//		return max / 2 * (t*t*((s + 1)*t + s) + 2) + min;
//	}
//	float OutBounce(float t, float totaltime, float max, float min) {
//		max -= min;
//		t /= totaltime;
//
//		if (t < 1 / 2.75)
//			return max * (7.5625f*t*t) + min;
//		else if (t < 2 / 2.75)
//		{
//			t -= 1.5f / 2.75f;
//			return max * (7.5625f*t*t + 0.75f) + min;
//		}
//		else if (t< 2.5 / 2.75)
//		{
//			t -= 2.25f / 2.75f;
//			return max * (7.5625f*t*t + 0.9375f) + min;
//		}
//		else
//		{
//			t -= 2.625f / 2.75f;
//			return max * (7.5625f*t*t + 0.984375f) + min;
//		}
//	}
//	float InBounce(float t, float totaltime, float max, float min) {
//		return max - OutBounce(totaltime - t, totaltime, max - min, 0) + min;
//	}
//	float InOutBounce(float t, float totaltime, float max, float min) {
//		if (t < totaltime / 2)
//			return InBounce(t * 2.0f, totaltime, max - min, max)*0.5f + min;
//		else
//			return OutBounce(t * 2.0f - totaltime, totaltime, max - min, 0)*0.5f + min + (max - min)*0.5f;
//	}
//	float Linear(float t, float totaltime, float max, float min) {
//		return (max - min)*t / totaltime + min;
//	}
//	float InElastic(float t, float totaltime, float max, float min) {
//		return 0;
//	}
//
//
//	/*
//	{
//	// t = 経過時間 b = 始点 c = 終点 - 始点 d = 持続時間
//	"ELASTIC_IN",
//	[](float t, const float b, const float c, const float d)
//	{
//	t = clamp(t, 0.0f, d);	//tを 0.0f <= t <= d　に丸め込み
//	if (t == 0)      return b;
//	if ((t /= d) == 1) return b + c;
//	float p = d*0.3f;
//	float a = c;
//	float s = p / 4;
//	t -= 1;
//	return -(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
//	}
//	},
//	{
//	"ELASTIC_OUT",
//	[](float t, const float b, const float c, const float d)
//	{
//	t = clamp(t, 0.0f, d);
//	if (t == 0)      return b;
//	if ((t /= d) == 1) return b + c;
//	float p = d*0.3f;
//	float a = c;
//	float s = p / 4;
//	return (a* std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p) + c + b);
//	}
//	},
//	{
//	"ELASTIC_INOUT",
//	[](float t, const float b, const float c, const float d)
//	{
//	t = clamp(t, 0.0f, d);
//	if (t == 0) return b;
//	if ((t /= d / 2) == 2) return b + c;
//	float p = d*(0.3f*1.5f);
//	float a = c;
//	float s = p / 4;
//	if (t < 1)
//	{
//	t -= 1;
//	return -0.5f*(a * std::pow(2.0f, 10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)) + b;
//	}
//	t -= 1;
//	return a * std::pow(2.0f, -10.0f*t) * std::sin((t*d - s)*(2.0f * m_pi) / p)*0.5f + c + b;
//	}
//	},
//	*/
//}

#pragma once
#include "../define.h"
#include <cmath>
class Easing
{
private:
	float cnt;
public:
	Easing():cnt(0) {};

	void init() {
		cnt = 0.0f;
	}
	//イージング用カウンタ
	float Time(float duration)
	{
		if (cnt <= duration)
		{
			cnt += 0.1f;
		}
		return cnt;
	}

	//t = 時間 d = 始点 c = 終点-始点 d = 経過時間
	//time = 時間 start = 始点 diff = 終点-始点 elps = 経過時間
	class Linear
	{
	public:
		float None(float time, float start, float diff, float elps)
		{
			return diff*time / elps + start;
		}
		float In(float time, float start, float diff, float elps)
		{
			return diff*time / elps + start;
		}
		float Out(float time, float start, float diff, float elps)
		{
			return diff*time / elps + start;
		}
		float InOut(float time, float start, float diff, float elps)
		{
			return diff*time / elps + start;
		}
	}linear;

	class Back
	{
	public:
		float In(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			float postFix = t /= d;
			return c*(postFix)*t*((s + 1)*t - s) + b;
		}
		float Out(float t, float b, float c, float d)
		{

			float s = 1.70158f;

			return c*((t = t / d - 1)*t*((s + 1)*t + s) + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			float s = 1.70158f;
			if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525f)) + 1)*t - s)) + b;
			float postFix = t -= 2;
			return c / 2 * ((postFix)*t*(((s *= (1.525f)) + 1)*t + s) + 2) + b;
		}
	}back;


	class Bounce
	{
	public:
		float Out(float t, float b, float c, float d)
		{

			if ((t /= d) < (1 / 2.75f))
			{
				return c*(7.5625f*t*t) + b;
			}
			else if (t < (2 / 2.75f))
			{
				float postFix = t -= (1.5f / 2.75f);
				return c*(7.5625f*(postFix)*t + .75f) + b;
			}
			else if (t < (2.5 / 2.75))
			{
				float postFix = t -= (2.25f / 2.75f);
				return c*(7.5625f*(postFix)*t + .9375f) + b;
			}
			else
			{
				float postFix = t -= (2.625f / 2.75f);
				return c*(7.5625f*(postFix)*t + .984375f) + b;
			}
		}
		float In(float t, float b, float c, float d)
		{
			return c - Out(d - t, 0, c, d) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t < d / 2) return In(t * 2, 0, c, d) * .5f + b;
			else return Out(t * 2 - d, 0, c, d) * .5f + c*.5f + b;
		}
	}bounce;

	class Circ
	{
	public:
		float In(float t, float b, float c, float d)	//バグあり
		{
			return -c * static_cast<float>((sqrt(1 - (t /= d)*t) - 1)) + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * static_cast<float>(sqrt(1 - (t = t / d - 1)*t)) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return -c / 2 * static_cast<float>((sqrt(1 - t*t) - 1)) + b;
			return c / 2 * static_cast<float>((sqrt(1 - t*(t -= 2)) + 1)) + b;
		}
	}circ;

	class Cubic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c*((t = t / d - 1)*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
			return c / 2 * ((t -= 2)*t*t + 2) + b;
		}
	}cubic;

	class Elastic
	{
	public:
		float In(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d*.3f;
			float a = c;
			float s = p / 4;
			float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
			return -static_cast<float>(postFix * sin((t*d - s)*(2 * (Math::PI)) / p)) + b;
		}

		float Out(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d) == 1) return b + c;
			float p = d*.3f;
			float a = c;
			float s = p / 4;
			return (static_cast<float>(a*pow(2, -10 * t) * sin((t*d - s)*(2 * static_cast<float>(Math::PI)) / p) + c + b));
		}

		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
			float p = d*(.3f*1.5f);
			float a = c;
			float s = p / 4;

			if (t < 1) {
				float postFix = static_cast<float>(a*pow(2, 10 * (t -= 1)));
				return -.5f*static_cast<float>((postFix* sin((t*d - s)*(2 * (Math::PI)) / p))) + b;
			}
			float postFix = static_cast<float>(a*pow(2, -10 * (t -= 1)));
			return static_cast<float>(postFix * sin((t*d - s)*(2 * static_cast<float>(Math::PI)) / p)*.5f + c + b);
		}
	}elastic;

	class Expo
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return (t == 0) ? b : c * static_cast<float>(pow(2, 10 * (t / d - 1)) + b);
		}
		float Out(float t, float b, float c, float d)
		{
			return (t == d) ? b + c : c * (static_cast<float>(-pow(2, -10 * t / d) + 1)) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if (t == 0) return b;
			if (t == d) return b + c;
			if ((t /= d / 2) < 1) return c / 2 * static_cast<float>(pow(2, 10 * (t - 1))) + b;
			return c / 2 * (static_cast<float>(-pow(2, -10 * --t) + 2)) + b;
		}
	}expo;

	class Quad
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c *(t /= d)*(t - 2) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return ((c / 2)*(t*t)) + b;
			return -c / 2 * (((t - 2)*(--t)) - 1) + b;
		}
	}quad;

	class Quart
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return -c * ((t = t / d - 1)*t*t*t - 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
			return -c / 2 * ((t -= 2)*t*t*t - 2) + b;
		}
	}quart;

	class Quint
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return c*(t /= d)*t*t*t*t + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c*((t = t / d - 1)*t*t*t*t + 1) + b;
		}
		float InOut(float t, float b, float c, float d)
		{
			if ((t /= d / 2) < 1) return c / 2 * t*t*t*t*t + b;
			return c / 2 * ((t -= 2)*t*t*t*t + 2) + b;
		}
	}quint;

	class Sine
	{
	public:
		float In(float t, float b, float c, float d)
		{
			return -c * static_cast<float>(cos(t / d * (Math::PI / 2))) + c + b;
		}
		float Out(float t, float b, float c, float d)
		{
			return c * static_cast<float>(sin(t / d * (Math::PI / 2))) + b;
		}

		float InOut(float t, float b, float c, float d)
		{
			return -c / 2 * static_cast<float>((cos(Math::PI*t / d) - 1)) + b;
		}
	}sine;

};