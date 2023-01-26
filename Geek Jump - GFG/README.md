# Geek Jump
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">&nbsp;Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.</span></p>

<pre><span style="font-size:18px"><strong>Example:</strong>
<strong>Input:</strong>
n = 4
height = {10 20 30 10}
<strong>Output:</strong>
20
<strong>Explanation:</strong>
<code>Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
so, total energy lost is 20 which is the minimum.</code></span></pre>

<p><strong><span style="font-size:18px"><code>Your Task:</code></span></strong><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function <strong>MinimumEnergy()&nbsp;</strong>which takes the array&nbsp;<strong>height</strong>, and integer <strong>n,</strong>&nbsp;and returns the minimum energy that is lost.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n)<br>
<strong>Expected Space Complexity:</strong> O(n)</span></p>

<p><span style="font-size:18px"><strong>Constraint:</strong><br>
1&lt;=n&lt;=100000<br>
1&lt;=height[i]&lt;=1000</span></p>
</div>