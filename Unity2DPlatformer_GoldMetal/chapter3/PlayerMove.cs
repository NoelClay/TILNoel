using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    Rigidbody2D rigid;
    public float maxSpeed;//상한값이다. 적절한 스피드는 게임창에서 확인하며 수정.
    float stopSpeed;//밑에 키보드를 땔때 속도 정지를 위해 코드를 추가하기 위함.

    SpriteRenderer spriteRenderer;

    Animator animator;

    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>(); //리지드바디에 컴포넌트 할당
        spriteRenderer = GetComponent<SpriteRenderer>();
        //스프라이트 렌더러의 속성값을 조건마다 변경하기 위해
        animator = GetComponent<Animator>();

    }
    // Start is called before the first frame update
    void Start()
    {
        
    }
    //AddForce로 키 입력을 받아 이동하는 방법이다.
    //일정한 픽셀로 정교한 움직임보다 물리적인 재미를 줄 수 있다.
    void FixedUpdate()
    {
        //AddForce로 키 입력을 받아 이동하는 방법이다.
        //일정한 픽셀로 정교한 움직임보다 물리적인 재미를 줄 수 있다.
        //FixedUpdate()는 프레임기반으로 호출되는 Update()와 달리
        //FixedTimestep에 설정된 값에 따라 일정한 간격으로 호출되는 함수이다.
        //그럼에도불구하고 이렇게 간단하게 짤경우에 생기는 문제가 있다.
        //키보드 입력을 꾹 누를경우에 fixedUpdate()마다 계속 AddForce()가 쌓여서
        //생각지도 못하게 너무 많은 힘이 가해진다는 것이다.
        //그래서 추가하는게 상한값이다.

        float h = Input.GetAxisRaw("Horizontal");
        rigid.AddForce(Vector2.right * h, ForceMode2D.Impulse);
        if (rigid.velocity.x > maxSpeed)//velocity는 vector2d값 따라서 x를 제한한다.
            rigid.velocity = new Vector2(maxSpeed, rigid.velocity.y);
        //new 생성자로 vector2를 초기화하는 방식으로 누적을 막는다. x는 maxSpeed y는 자기자신 속도
        else if (rigid.velocity.x < maxSpeed*(-1))//왼쪽이동은 마이너스값이므로 이렇게 검사하여 초기화
            rigid.velocity = new Vector2(maxSpeed*(-1), rigid.velocity.y);

    }

    // Update is called once per frame
    void Update()
    {
        //키보드가 때지는걸 프레임단위로 검사하는 코드이다.
        if (Input.GetButtonUp("Horizontal"))
        {
            //rigid.velocity.normalized; 벡터 크기를 단위벡터 즉 방향만 가진 벡터로 만드는 기능
            stopSpeed = (rigid.velocity.normalized.x) * (0.5f);
            rigid.velocity = new Vector2(stopSpeed, rigid.velocity.y);
        }
        //키 입력이 일어날때 옳바른 방향 바라보기
        if (Input.GetButtonDown("Horizontal"))
            spriteRenderer.flipX = Input.GetAxisRaw("Horizontal") == -1;
        //오른쪽 키를 누르면 +1이고 이것은 거짓이 되므로 flipX엔 거짓 할당되어 체크해제
        //왼쪽 키를 누르면 -1이고 참이되어 flopX엔 참 할당되어 체크함. 따라서 플립이 일어남.

        //객체의 속도를 체크해서 속도가 있을땐 워킹 애니메이션 재생
        if (Mathf.Abs(rigid.velocity.x) < 0.3f)
            animator.SetBool("isWalking", false);
        else
            animator.SetBool("isWalking", true);
    }
}
