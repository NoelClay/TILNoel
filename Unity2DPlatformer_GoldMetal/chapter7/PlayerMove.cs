using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    Rigidbody2D rigid;
    public float maxSpeed;//상한값이다. 적절한 스피드는 게임창에서 확인하며 수정.
    float stopSpeed;//밑에 키보드를 땔때 속도 정지를 위해 코드를 추가하기 위함.
    public float jumpPower;


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

        //Landing Platform

        
        if(rigid.velocity.y < 0) 
        {
            Debug.DrawRay(rigid.position, Vector3.down, new Color(0, 1, 0));
            //에디터 상에서만 ray를 그려주는 함수이다.

            RaycastHit2D rayHit = Physics2D.Raycast(rigid.position, Vector3.down, 1, LayerMask.GetMask("Platform"));
            //레이캐스트2d를 담을 변수를 선언하고 physics2d.raycast()함수를 이용하여 생성한다.
            //Physics2D.Raycast(레이캐스트 시작점, 방향, 크기);
            //레이캐스트함수를 이용해 쏜 정보가 rayhit에 담긴 형태이다.

            //마지막에 있는 레이어마스크를 설정하면 그거에 해당하는 콜라이더만 담을것이다.

            if (rayHit.collider != null) //충돌된 콜라이더를 검사해서 null이 아니라면
            {
                if (rayHit.distance < 1f) //바닥에 닿았을때 즉 레이캐스트를 쏘는 중심부와
                {    //탐지하려는바닥 콜라이더 사이의 거리가 0.5보다 작아졌을때만
                    Debug.Log(rayHit.collider.name);//충돌된 정보의 이름을 출력하는데
                                                    //raycast가 쏜 정보는 콜라이더 하나밖에 안담긴다. 플레이어 중심부에서
                                                    //레이캐스트를 쏘면 플레이어의 충돌체를 담아오기때문에 바닥감지가 안된다.
                                                    //그래서 추가하는게 레이어마스크.

                    animator.SetBool("isJumping", false);
                    //바닥에 닿았다면 점프파라미터를 펄스로 바꾸고 트랜지션에 넘겨서 트랜지션에의해
                    //idle이나 walk 상태로 돌아가게 한다.
                    //하지만 이렇게만 하게될 경우 예외가 생기는데 처음에 점프할때도 이미 0.5보다 작기 때문에
                    //점프 누를때 true로 바꾸는 것과 레이캐스트에의해 false로 바꾸는게 충돌된다.
                    //따라서 점프할때는 레이캐스트를 하지 않고 착륙하려할때만 레이캐스트를 호출하면 될 것이다.
                }
            }
        }

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

        //점프기능 구현
        if (Input.GetButtonDown("Jump") && !animator.GetBool("isJumping"))
        {
            rigid.AddForce(Vector2.up * jumpPower, ForceMode2D.Impulse);
            //물리 점프

            animator.SetBool("isJumping", true);
            //애니메이터의 상태를 변경하기위한
        }
    }
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Enemy")
            OnDamaged(collision.transform.position);
    }
    void OnDamaged(Vector2 targetPos)
    {
        gameObject.layer = 11;
        spriteRenderer.color = new Color(1, 1, 1, 0.5f);

        int dir = transform.position.x - targetPos.x > 0 ? 1 : -1;
        rigid.AddForce(new Vector2(dir, 1)*10, ForceMode2D.Impulse);
        animator.SetTrigger("doDamaged");
        Invoke("OffDamaged", 3);
    }
    void OffDamaged()
    {
        gameObject.layer = 10;
        spriteRenderer.color = new Color(1, 1, 1, 1);
    }
}
