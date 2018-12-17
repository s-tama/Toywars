//
// Math.h
//
#pragma once

#include <string>
#include <vector>
#include <locale>
#include <winstring.h>
#include <d3d11.h>
#include <SimpleMath.h>

namespace MyLibrary
{
	/// <summary>
	/// 数学クラス
	/// </summary>
	class Math
	{
	public:

		/// <summary>
		/// 2点間の距離を求める
		/// </summary>
		/// <param name="p1">点1</param>
		/// <param name="p2">点2</param>
		/// <returns>距離</returns>
		template<typename T>
		static T Distance(T p1, T p2)
		{
			auto length = p1 - p2;
			return Abs<T>(length);
		}
		static float Distance(DirectX::SimpleMath::Vector3 v1, DirectX::SimpleMath::Vector3 v2)
		{
			DirectX::SimpleMath::Vector3 d = v1 - v2;
			float sq = (d.x * d.x) + (d.y * d.y) + (d.z * d.z);
			return sqrt(sq);
		}

		/// <summary>
		/// 絶対値を求める
		/// </summary>
		/// <param name="num">数値</param>
		/// <returns>絶対値</returns>
		template<typename T>
		static T Abs(T num)
		{
			if (num < 0)
				num *= -1;
			return num;
		}

		/// <summary>
		/// 文字列の長さを求める
		/// </summary>
		/// <param name="str"></param>
		/// <returns></returns>
		static int StrLen(std::string str)
		{
			int length = 0;
			if (str[length] != '\0')
			{
				length++;
			}
			return length;
		}

		/// <summary>
		/// 乱数の取得
		/// </summary>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		template<typename T>
		static T GetRand(T min, T max)
		{
			T ans = min + static_cast<T>((rand() * (max - min + 1) / (1 + RAND_MAX)));
			return ans;
		}
		static int GetRand(int max)
		{
			int rnd;
			srand((UINT)time(NULL));
			rnd = rand() % max;
			return rnd;
		}

		/// <summary>
		/// stringからwstringに変換
		/// </summary>
		/// <param name="refSrc"></param>
		/// <param name="codePage"></param>
		/// <returns></returns>
		static std::wstring StringToWString(const std::string& refSrc, unsigned int codePage = CP_ACP)
		{
			std::vector<wchar_t> buffer(MultiByteToWideChar(codePage, 0, refSrc.c_str(), -1, nullptr, 0));
			MultiByteToWideChar(codePage, 0, refSrc.c_str(), -1, &buffer.front(), buffer.size());
			return std::wstring(buffer.begin(), buffer.end());
		}

		/// <summary>
		/// wstringからstringに変換
		/// </summary>
		/// <param name="refSrc"></param>
		/// <param name="codePage"></param>
		/// <returns></returns>
		static std::string WStringToString(const std::wstring& refSrc, unsigned int codePage = CP_OEMCP)
		{
			std::vector<char> buffer(WideCharToMultiByte(codePage, 0, refSrc.c_str(), -1, nullptr, 0, nullptr, nullptr));
			WideCharToMultiByte(codePage, 0, refSrc.c_str(), -1, &buffer.front(), buffer.size(), nullptr, nullptr);
			return std::string(buffer.begin(), buffer.end());
		}
		


		/// <summary>
		/// 現在の文字列から指定された文字列を削除する（一致した最初の文字のみ）
		/// </summary>
		/// <param name="nowStr">現在の文字列</param>
		/// <param name="str">削除する最初の文字列</param>
		/// <returns>結果</returns>
		static std::string EraseStringFirst(std::string nowStr, std::string str)
		{
			for (unsigned int i = 0; i < str.size(); i++)
			{
				for (size_t c = nowStr.find_first_of(str[i]); c != std::string::npos; c = c = nowStr.find_first_of(" "))
				{
					nowStr.erase(c, 1);
				}
			}
			return nowStr;
		}

		/// <summary>
		/// 指定された文字列の文字をすべて現在の文字列から削除する
		/// </summary>
		/// <param name="str">削除する文字列</param>
		/// <param name="nowStr">現在の文字列</param>
		/// <returns>結果</returns>
		static std::string EraseStringAll(std::string nowStr, std::string str)
		{
			size_t c;
			while ((c = nowStr.find_first_of(str)) != std::string::npos)
			{
				nowStr.erase(c, 1);
			}
			return nowStr;
		}
	};
}
