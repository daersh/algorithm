# [Gold V] Bronze Cow Party - 6248 

[문제 링크](https://www.acmicpc.net/problem/6248) 

### 성능 요약

메모리: 3240 KB, 시간: 8 ms

### 분류

그래프 이론, 최단 경로, 데이크스트라

### 제출 일자

2026년 03월 21일 12:39:17

### 문제 설명

<p>One cow from each of N farms (1 <= N <= 1000) conveniently numbered 1..N is attending the big cow party to be held at farm #X (1 <= X <= N). Each of M (1 <= M <= 100,000) bidirectional roads connects one farm to another. It is always possible to travel from one farm to another on the roads. Traversing road i requires Ti (1 <= Ti <= 100) units of time. One or more pairs of farms might be directly connected by more than one road.</p>

<p>After all the cows gathered at farm #X, they realized that every single cow left her party favors back at the farm. They decided to suspend the party and send all the cows back to get the party favors. The cows all travel optimal routes to their home farm and back to the party. What is the minimum number of time units the party must be suspended?</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers, respectively: N, M, and X</li>
	<li>Lines 2..M+1: Line i+1 describes road i with three space-separated integers, respectively: Ai, Bi, and Ti. The described road connects Ai and Bi and requires Ti time units to traverse.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: One integer: the minimum amount of time the party must be suspended.</li>
</ul>

