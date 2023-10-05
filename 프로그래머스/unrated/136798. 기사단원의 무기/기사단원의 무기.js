function solution(number, limit, power) {
    var answer = 0;
  
    // 1) numbers이하의 자연수만 존재하기 때문에 numbers+1만큼 배열 생성
    const numsArr = new Array(number+1).fill(0);

    /*
      2) 약수의 개수를 한번에 count하는 반복문
    	 인덱스 번호를 자연수로 정하고, 해당 자연수에 대한 약수를 
         반복문을 통해 하나씩 증가시킨다.
    */
    for(let i = 1;i<=number;i++) {
        for(let j = i;j<=number;j += i) {
            numsArr[j] += 1;
        }
    }

    // 3) cv(현재 값)이 limit 값보다 크면 pv(누적 값)에 power만큼 더하고, 작으면 cv만큼 더한다
    return numsArr.reduce((pv,cv) => { return cv > limit ? pv+power : pv+cv }, 0);
}