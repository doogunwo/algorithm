function solution(s, skip, index) {
  let answer = "";

  // 정규식을 이용한다.
  // a - z의 알파벳 중 skip에 포함된 단어를 제외한 단어의 배열을 추출한다.
  const regex = new RegExp(`[^${skip}]`, "g");
  const alpabet = "abcdefghijklmnopqrstuvwxyz".match(regex);
  // match() 메서드를 이용하면 w b q d 를 제외한 단어의 배열이 나온다.

  for (const c of s) {
    // 단어를 제외했으니 단어를 하나씩 확인하면서 index를 더해준다.
    const idx = alpabet.indexOf(c) + index;

    // 더한 값이 단어의 배열 크기를 넘어가면 안되므로
    // idx % alpabet의 길이를 넣어줌으로서 앞으로 다시 돌아가게 한다.
    answer += alpabet[idx % alpabet.length];
  }
  return answer;
}
